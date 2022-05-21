#include "StateManager.h"

StateManager StateManager::s_instance;

StateManager &StateManager::Get()
{
    return s_instance;
}

StateManager::StateManager()
{

    std::random_device rd;
    random_eng = std::default_random_engine(rd());

    NewGame();

}

void StateManager::NewGame(){
    // if(scenes.contains("main")){
    //     scenes.erase("main");
    // }


    game_state.round = 0;
    game_state.enemies_count = 0;
    game_state.enemies_spawn_remain = 0;


    game_state.health_buffs = 0;
    game_state.armor_buffs = 0;
    game_state.attack_damage_buffs = 0;
    game_state.attack_speed_buffs = 0;
    game_state.lifesteal_buffs = 0;
    game_state.movement_buffs = 0;
    game_state.jump_height_buffs = 0;


    size_t last_spawn_tick = 0;

    player = std::make_shared<Player>(0.5, 0.5);

    main_scene = std::make_shared<MainScene>();
    scenes.insert_or_assign("main", main_scene);
    main_scene->AddEntity(player);

    current_scene = "main";

    NextRound();

}

void StateManager::Update(double delta)
{
    scenes[current_scene]->update(delta);
}

void StateManager::Tick()
{

    if(game_state.enemies_spawn_remain && ticks - game_state.last_spawn_tick >= 60) {
        game_state.enemies_spawn_remain--;
        game_state.enemies_count++;
        game_state.last_spawn_tick = ticks;

        std::uniform_real_distribution<double> distr(0.000001, 0.9999);

        double x = std::fmod(distr(random_eng), 0.85);
        double y = std::fmod(distr(random_eng), 0.4);
   

        append_entity.push_back(std::make_shared<Enemy>(x,y));

    }


    if (append_entity.size())
    {
        for(auto ent: append_entity){
            main_scene->AddEntity(ent);
        }
        append_entity.clear();
    }

    scenes[current_scene]->tick();

    if(game_state.enemies_spawn_remain == 0 && game_state.enemies_count == 0){
        EndRound();
    }

    if(current_scene == "main"){
        ticks++;
    }
}

void StateManager::Render()
{
    //map.render();


    scenes[current_scene]->render();


}

void StateManager::AddEntity(shared_ptr<Entity> ent)
{
    append_entity.push_back(ent);
}

size_t StateManager::GetTicks() const
{
    return ticks;
}

void StateManager::NextRound()
{
    game_state.round++;
    game_state.enemies_spawn_remain = ( 3 + (game_state.round*0.5));
}
void StateManager::EndRound()
{
    NextRound();
}
void StateManager::Death()
{
    scenes.insert_or_assign("score", std::make_shared<ScoreScene>(game_state.round));
    current_scene = "score";

}


vector<shared_ptr<Entity>> StateManager::GetEntities(){
    return main_scene->GetEntities();
}
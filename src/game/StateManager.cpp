#include "StateManager.h"

StateManager StateManager::s_instance;

StateManager &StateManager::Get()
{
    return s_instance;
}

StateManager::StateManager()
{
    player = std::make_shared<Player>(0.5, 0.5);
    entities.push_back(player);

    entities.push_back(std::make_shared<Enemy>(0.2, 0.2));
    entities.push_back(std::make_shared<Enemy>(0.3, 0.2));
    entities.push_back(std::make_shared<Enemy>(0.9, 0.2));
    entities.push_back(std::make_shared<Enemy>(0.6, 0.2));
    entities.push_back(std::make_shared<Enemy>(0.4, 0.2));
}

void StateManager::Update(double delta)
{
    for (auto e : entities)
    {
        e->update(delta);
    }
}

void StateManager::Tick()
{

    auto to_remove = std::remove_if(entities.begin(), entities.end(), [](shared_ptr<Entity> e)
                                    { return e->next_remove; });

    entities.erase(to_remove, entities.end());

    if (append_entity.size())
    {
        move(append_entity.begin(), append_entity.end(), std::back_inserter(entities));
        append_entity.clear();
    }

    for (auto e : entities)
    {
        e->tick();
    }

    ticks++;


    if(game_state.enemies_spawn_remain == 0 && game_state.enemies_count == 0){
        EndRound();
    }
}

void StateManager::Render()
{
    map.render();
    for (auto e : entities)
    {
        e->render();
    }

    auto &window = Window::Get();

    SDL_SetRenderDrawColor(window.get_renderer(), 255, 255, 255, 255);

    SDL_Rect hp{
        .x = 60,
        .y = 60,
        .h = 30,
        .w = 240};

    SDL_RenderDrawRect(window.get_renderer(), &hp);

    hp.w = std::max((int)((player->state.health / player->stats.max_health) * 238.0), 0);
    hp.x += 1;
    hp.y += 1;
    hp.h -= 2;

    SDL_SetRenderDrawColor(window.get_renderer(), 255, 0, 0, 255);
    SDL_RenderFillRect(window.get_renderer(), &hp);

    auto font = ResourceManager::Get().GetFont("ancient24");
    SDL_Color color = {
        .r = 255, .b = 255, .g = 255, .a = 255};

    auto current_health = std::max((int)player->state.health, 0);
    auto text = font->Text(std::to_string(current_health) + std::string("/") + std::to_string((int)player->stats.max_health), color);

    SDL_Rect r_text;
    r_text.x = 130;
    r_text.y = 60;
    r_text.w = 120;
    r_text.h = 30;

    SDL_RenderCopy(window.get_renderer(), text->get(), nullptr, &r_text);
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
}
void StateManager::Death()
{
}

#include "main_scene.h"

void MainScene::update(double delta)
{
    for (auto entity : this->entities)
    {
        entity->update(delta);
    }
}

void MainScene::tick()
{

    auto to_remove = std::remove_if(entities.begin(), entities.end(), [](shared_ptr<Entity> e)
                                    { return e->next_remove; });
    entities.erase(to_remove, entities.end());

    for (auto entity : this->entities)
    {
        entity->tick();
    }
}

void MainScene::render()
{   

    map.render();

    // Render all entities
    for (auto entity : this->entities)
    {
        entity->render();
    }

    // Render Stats (hp, round, bonuses ...)

    auto &window = Window::Get();

    auto &state_manager = StateManager::Get();
    auto player = state_manager.player;

    SDL_SetRenderDrawColor(window.get_renderer(), 255, 255, 255, 255);

    SDL_Rect hp_rect{
        .x = 60,
        .y = 60,
        .h = 30,
        .w = 240};

    SDL_RenderDrawRect(window.get_renderer(), &hp_rect);

    hp_rect.w = std::max((int)((player->state.health / player->stats.max_health) * 238.0), 0);
    hp_rect.x += 1;
    hp_rect.y += 1;
    hp_rect.h -= 2;

    SDL_SetRenderDrawColor(window.get_renderer(), 255, 0, 0, 255);
    SDL_RenderFillRect(window.get_renderer(), &hp_rect);

    auto font = ResourceManager::Get().GetFont("ancient24");
    SDL_Color color = {
        .r = 255, .b = 255, .g = 255, .a = 255};

    auto current_health = std::max((int)player->state.health, 0);
    auto health_text = font->Text(std::to_string(current_health) + std::string("/") + std::to_string((int)player->stats.max_health), color);

    SDL_Rect r_text;
    r_text.x = 135;
    r_text.y = 62;
    r_text.w = 90;
    r_text.h = 26;

    SDL_RenderCopy(window.get_renderer(), health_text->get(), nullptr, &r_text);


    auto round_text = font->Text(std::to_string(state_manager.game_state.round), color);
    SDL_Rect round_rect;

    round_rect.x = static_cast<int>(0.90 * window.GetWidth());
    round_rect.y = static_cast<int>(0.05 * window.GetHeight());
    round_rect.w = static_cast<int>(0.02 * window.GetWidth());
    round_rect.h = static_cast<int>(0.06 * window.GetHeight());

    if(state_manager.game_state.round >= 10){
        round_rect.w *= 2.1;
    }

    SDL_RenderCopy(window.get_renderer(), round_text->get(), nullptr, &round_rect);


}

void MainScene::AddEntity(shared_ptr<Entity> entity)
{
    this->entities.push_back(entity);
}


vector<shared_ptr<Entity>> MainScene::GetEntities(){
    return entities;
}


void MainScene::NextRound(){
    auto player = StateManager::Get().player;

    auto to_remove = std::remove_if(entities.begin(), entities.end(), [player](shared_ptr<Entity> e)
                                    { return e.get() != player.get(); });
    entities.erase(to_remove, entities.end());

}

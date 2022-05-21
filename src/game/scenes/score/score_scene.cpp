#include "score_scene.h"



ScoreScene::ScoreScene(int score){
    this->score = score;
}

void ScoreScene::tick(){

}

void ScoreScene::update(double delta){

}

void ScoreScene::render(){
    auto &window = Window::Get();

    auto font = ResourceManager::Get().GetFont("ancient24");

    std::string text_over("Game Over");
    std::string text("Score: ");
    text += std::to_string(score);

    SDL_Color color = {
        .r = 255,
        .g = 255,
        .b = 255,
        .a = 255,
    };
    auto t_over = font->Text(text_over, color);

    SDL_Rect r_over = {
        .x = (int)(0.5 * (window.GetWidth()) - 225),
        .y = (int)(0.2 * window.GetHeight()),
        .w = 450,
        .h = 90
    };

    SDL_RenderCopy(window.get_renderer(), t_over->get(), nullptr, &r_over);

    auto t_score = font->Text(text, color);

        SDL_Rect r_score = {
        .x = (int)(0.5 * (window.GetWidth()) - 125),
        .y = (int)(0.3 * window.GetHeight()),
        .w = 250,
        .h = 50
    };

    SDL_RenderCopy(window.get_renderer(), t_score->get(), nullptr, &r_score);

    

}

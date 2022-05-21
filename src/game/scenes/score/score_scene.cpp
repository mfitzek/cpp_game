#include "score_scene.h"

ScoreScene::ScoreScene(int score)
{
    this->score = score;
}

void ScoreScene::tick()
{

    if (Input::Get().GetMouseBtn(SDL_BUTTON_LEFT) && m_pressed == false)
    {
        m_pressed = true;
        BoundingBox again_bbox(0.425, 0.8, 0.15, 0.05);

        auto &window = Window::Get();
        int mx, my;
        Input::Get().GetMouseCoords(mx, my);

        double mouse_x = (double)mx / (double)window.GetWidth();
        double mouse_y = (double)my / (double)window.GetHeight();

        BoundingBox mbox(mouse_x, mouse_y, 0.001, 0.001);

        if (mbox.CheckCollision(again_bbox))
        {
            StateManager::Get().NewGame();
        }
    }
    if(Input::Get().GetMouseBtn(SDL_BUTTON_LEFT) == false){
        m_pressed = false;
    }
}

void ScoreScene::update(double delta)
{
}

void ScoreScene::render()
{
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
        .y = (int)(0.05 * window.GetHeight()),
        .w = 450,
        .h = 90};

    SDL_RenderCopy(window.get_renderer(), t_over->get(), nullptr, &r_over);

    auto t_score = font->Text(text, color);

    SDL_Rect r_score = {
        .x = (int)(0.5 * (window.GetWidth()) - 125),
        .y = (int)(0.15 * window.GetHeight()),
        .w = 250,
        .h = 50};

    SDL_RenderCopy(window.get_renderer(), t_score->get(), nullptr, &r_score);

    auto t_play_again = font->Text("Play again", color);

    SDL_Rect r_again = {
        .x = (int)(0.425 * (window.GetWidth())),
        .y = (int)(0.8 * window.GetHeight()),
        .w = (int)(0.15 * window.GetWidth()),
        .h = (int)(0.05 * window.GetHeight())};

    SDL_RenderCopy(window.get_renderer(), t_play_again->get(), nullptr, &r_again);

    r_again.x -= 10;
    r_again.y -= 10;
    r_again.w += 20;
    r_again.h += 20;

    SDL_SetRenderDrawColor(window.get_renderer(), 255, 255, 255, 255);
    SDL_RenderDrawRect(window.get_renderer(), &r_again);
}

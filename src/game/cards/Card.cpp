#include "Card.h"

Card::Card(CardType _type, double _x, double _y)
{
    this->type = _type;
    this->x = _x;
    this->y = _y;
}

BoundingBox Card::GetBounds()
{
    return BoundingBox(x, y, width, height);
}

void Card::render()
{

    std::string card_text1;
    std::string card_text2;

    switch (type)
    {
    case CardType::AttackDamage:
        card_text1 = "Attack Damage";
        card_text2 = "+2";
        break;
    case CardType::AttackSpeed:
        card_text1 = "Attack Speed";
        card_text2 = "+12%";
        break;
    case CardType::LifeSteal:
        card_text1 = "Life Steal";
        card_text2 = "+3%";
        break;
    case CardType::Health:
        card_text1 = "Health";
        card_text2 = "+10";
        break;
    case CardType::Armor:
        card_text1 = "Armor";
        card_text2 = "+5%";
        break;
    case CardType::Movement:
        card_text1 = "Movement Speed";
        card_text2 = "+10%";
        break;
    }

    auto font = ResourceManager::Get().GetFont("ancient24");

    SDL_Color color{
        .r = 255,
        .g = 255,
        .b = 255,
        .a = 255,
    };

    auto text1 = font->Text(card_text1, color);
    auto text2 = font->Text(card_text2, color);

    auto &window = Window::Get();

    SDL_SetRenderDrawColor(window.get_renderer(), 255, 255, 255, 255);

    SDL_Rect card_rect = {
        .x = (int)(x * window.GetWidth()),
        .y = (int)(y * window.GetHeight()),
        .w = (int)(width * window.GetWidth()),
        .h = (int)(height * window.GetHeight()),
    };

    SDL_RenderDrawRect(window.get_renderer(), &card_rect);

    SDL_Rect rect_text1{
        .x = (int)(x * window.GetWidth() + (width / 8) * window.GetWidth()),
        .y = (int)((y + (height / 3)) * window.GetHeight()),
        .w = (int)((width * 6 / 8) * window.GetWidth()),
        .h = (int)((height / 8) * window.GetHeight()),
    };

    SDL_Rect rect_text2{
        .x = (int)((x + (width / 3)) * window.GetWidth()),
        .y = (int)((y + (height / 3) + (height / 8)) * window.GetHeight()),
        .w = (int)((width / 4) * window.GetWidth()),
        .h = (int)((height / 8) * window.GetHeight()),
    };

    SDL_RenderCopy(window.get_renderer(), text1->get(), nullptr, &rect_text1);
    SDL_RenderCopy(window.get_renderer(), text2->get(), nullptr, &rect_text2);
}

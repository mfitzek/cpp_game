#include "card_scene.h"



CardScene::CardScene()
{
    std::uniform_int_distribution<int> distr(0, 5);

    double x = 0.1;

    for(int i = 0; i < 3; i++){

        CardType card_type = CardType::AttackDamage;
        while(true){
            bool ok = true;

            auto rnd = distr(StateManager::Get().random_eng);
            card_type = static_cast<CardType>(rnd);

            for(auto& card:cards){
                if(card.type == card_type){
                    ok = false;
                    break;
                }
            }

            if(ok){
                break;
            }
        }

        cards.emplace_back(card_type, x , 0.1);
        x += 0.3;

    }


}

void CardScene::tick()
{

    if (Input::Get().GetMouseBtn(SDL_BUTTON_LEFT) && m_pressed == false)
    {
        m_pressed = true;
        

        auto &window = Window::Get();
        int mx, my;
        Input::Get().GetMouseCoords(mx, my);

        double mouse_x = (double)mx / (double)window.GetWidth();
        double mouse_y = (double)my / (double)window.GetHeight();

        BoundingBox mbox(mouse_x, mouse_y, 0.001, 0.001);


        for(auto& card: cards){
            if(card.GetBounds().CheckCollision(mbox)){
                StateManager::Get().AddCard(card);
                break;
            }
        }
    
    }
    if(Input::Get().GetMouseBtn(SDL_BUTTON_LEFT) == false){
        m_pressed = false;
    }
}

void CardScene::update(double delta)
{
}

void CardScene::render()
{
    auto &window = Window::Get();

    for(auto& card: this->cards) {
        card.render();
    }

 
}

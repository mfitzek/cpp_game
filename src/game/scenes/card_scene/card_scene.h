#pragma once




#include "../../StateManager.h"
#include "../../cards/Card.h"
#include "../scene.h"

#include "../../collisions/BoundingBox.h"
#include "../../window.h"
#include "../../ResourceManager/ResourceManager.h"
#include "../../ResourceManager/Font.h"
#include "../../input.h"

#include <vector>

class Card;

class CardScene: public Scene{
    private:
        bool m_pressed = false;
        std::vector<Card> cards;

    public:
        CardScene();
        void tick()override;
        void update(double delta) override;
        void render() override;
};




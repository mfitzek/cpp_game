#pragma once

#include "SDL.h"

#include "../ResourceManager/ResourceManager.h"
#include "../ResourceManager/Font.h"
#include "../collisions/BoundingBox.h"
#include "../StateManager.h"

#include <string>

enum class CardType
{
    AttackDamage = 0,
    AttackSpeed = 1,
    LifeSteal = 2,
    Health = 3,
    Armor = 4,
    Movement = 5,
};

class Card
{
private:
    double x, y;
    double width = 0.25;
    double height = 0.8;



public:
    Card(CardType type, double x, double y);
    CardType type;
    void render();
    BoundingBox GetBounds();
};

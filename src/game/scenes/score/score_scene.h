#pragma once


#include "../scene.h"

#include "../../collisions/BoundingBox.h"
#include "../../window.h"
#include "../../ResourceManager/ResourceManager.h"
#include "../../ResourceManager/Font.h"
#include "../../input.h"

#include "../../StateManager.h"

#include <iostream>

#include <SDL.h>

#include <string>


class ScoreScene: public Scene{

    private:
        int score;
        bool m_pressed = false;

    public:
        ScoreScene(int round);
        void tick()override;
        void update(double delta) override;
        void render() override;


};

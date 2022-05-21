#pragma once


#include "../scene.h"

#include "../../window.h"
#include "../../ResourceManager/ResourceManager.h"
#include "../../ResourceManager/Font.h"

#include <SDL.h>

#include <string>


class ScoreScene: public Scene{

    private:
        int score;

    public:
        ScoreScene(int round);
        void tick()override;
        void update(double delta) override;
        void render() override;


};

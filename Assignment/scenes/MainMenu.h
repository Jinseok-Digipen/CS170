#pragma once

#include "Button.h"
#include"Scene.h"
class Game;

class MainMenu :public Scene
{
    Button play, options, credits;
    
public:
    MainMenu(Game& the_game);

    void Update() override;
    void Draw() const override;
};

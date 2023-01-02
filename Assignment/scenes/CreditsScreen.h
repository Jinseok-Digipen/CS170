// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#pragma once

#include "Button.h"
#include "Scene.h"
class Game;

class CreditsScreen : public Scene
{
    Button mainMenu;
    

public:
    CreditsScreen(Game& the_game);

    void Update();
    void Draw() const;
};

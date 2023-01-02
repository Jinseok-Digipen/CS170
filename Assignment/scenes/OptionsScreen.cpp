// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#include "OptionsScreen.h"

#include "Game.h"
#include "SceneDrawing.h"


#include <doodle/environment.hpp>
#include <doodle/random.hpp>
#include <iostream>

OptionsScreen::OptionsScreen(Game& the_game)
    : background(doodle::Width / 2.0, doodle::Height / 2.0, "Random Color"),
      mainMenu(doodle::Width / 2.0, doodle::Height - 50.0, "Main Menu"),Scene(the_game)
{
}

void OptionsScreen::Update()
{
    if (background.DidClickButton())
    {
        Scene::game().BackgroundColor =
            doodle::Color(doodle::random(255.0), doodle::random(255.0), doodle::random(255.0));
    }
    else if (mainMenu.DidClickButton())
    {
        std::cout << "Main Menu!\n";
        Scene::game().QueueNextScene(GameScenes::MAIN_MENU);
    }
}

void OptionsScreen::Draw() const
{
    
    Draw_Title("Options");
    background.Draw();
    mainMenu.Draw();
}

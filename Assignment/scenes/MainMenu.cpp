#include "MainMenu.h"
#include "Game.h"
#include "SceneDrawing.h"


#include <doodle/environment.hpp>
#include <iostream>
#include"doodle/drawing.hpp"
MainMenu::MainMenu(Game& the_game)
    : play(doodle::Width / 2.0, doodle::Height * 2.0 / 5.0, "Play"),
      options(doodle::Width / 2.0, doodle::Height * 3.0 / 5.0, "Options"),
      credits(doodle::Width / 2.0, doodle::Height * 4.0 / 5.0, "Credits"), Scene(the_game)
{
}

void MainMenu::Update()
{
    if (play.DidClickButton())
    {
        std::cout << "Play!\n";
        //game.QueueNextScene(GameScenes::PLAY);
        Scene::game().QueueNextScene(GameScenes::PLAY);
    }
    else if (options.DidClickButton())
    {
        std::cout << "Options!\n";
        Scene::game().QueueNextScene(GameScenes::OPTIONS);
        
    }
    else if (credits.DidClickButton())
    {
        std::cout << "Credits!\n";
        Scene::game().QueueNextScene(GameScenes::CREDITS);
    }
}

void MainMenu::Draw() const
{
    doodle::clear_background(Scene::game().BackgroundColor);
    Draw_Title("Main Menu");
    
    play.Draw();
    options.Draw();
    credits.Draw();
}

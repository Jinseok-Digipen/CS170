// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#include "Game.h"
#include <doodle/drawing.hpp>
#include"MainMenu.h"
#include"OptionsScreen.h"
#include"CreditsScreen.h"
#include"PlayScreen.h"
#include<memory>
void Game::Setup()
{

    

    scenes[GameScenes::MAIN_MENU] = std::make_unique<MainMenu>(*this);
    scenes[GameScenes::OPTIONS]   = std::make_unique<OptionsScreen>(*this);
    scenes[GameScenes::CREDITS]   = std::make_unique<CreditsScreen>(*this);
    scenes[GameScenes::PLAY]      = std::make_unique<PlayScreen>(*this);

    //Initialize currentScene and queendScene to MAIN_MENU
    currentScene = scenes[GameScenes::MAIN_MENU].get();
    queuedScene  = scenes[GameScenes::MAIN_MENU].get();
}


void Game::Update()
{

    if (currentScene!=queuedScene)
    {
        currentScene = queuedScene;
    }
        currentScene->Update();
    
  
}

void Game::Draw() const
{
    doodle::clear_background(BackgroundColor);
    currentScene->Draw();
}

void Game::QueueNextScene(GameScenes scene)
{
    queuedScene = scenes[scene].get();

}



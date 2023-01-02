// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#pragma once
#include <doodle/color.hpp>

#include "Scene.h"
#include <map>
#include <memory>

enum class GameScenes
{
    MAIN_MENU,
    CREDITS,
    OPTIONS,
    PLAY
};

class Game
{
    //Now we use Polymorpsysm concept for our class 
    //There are two big importatnt knowledge related to Inheritance  
    //First Base class pointer can point derived class pointer 
    //even if our pointer point derived class if we use virtual keyword it will used derived class 
    Scene*                                       currentScene{ nullptr };
    Scene*                                       queuedScene{ nullptr };
    std::map<GameScenes, std::unique_ptr<Scene>> scenes{};

public:
    Game() = default;

    void          Setup();
    void          Update();
    void          Draw() const;
    doodle::Color BackgroundColor{ 120.0 };
    void          QueueNextScene(GameScenes scene);
};

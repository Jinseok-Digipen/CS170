#include"PlayScreen.h"
#include"doodle/environment.hpp"
#include"doodle/drawing.hpp"
#include<iostream>
PlayScreen::PlayScreen(Game& the_game) : Scene(the_game),
test(doodle::Width / 2.0, doodle::Height * 2.0 / 5.0, "test")
{
    
}

void PlayScreen::Update()
{
    if (test.DidClickButton()==true)
    {
        std::cout << "test button" << '\n';
    }
}

void PlayScreen::Draw() const
{

    test.Draw();
}

// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#include "Game.h"
#include <doodle/window.hpp>

int main(void)
{
    //Create Window 
    doodle::create_window(800, 600);

    //Create Game Instance this Game class include 3 gamestage 
    Game game;


    game.Setup();

    while (!doodle::is_window_closed())
    {
        doodle::update_window();
        game.Update();
        game.Draw();
    }

    return 0;
}

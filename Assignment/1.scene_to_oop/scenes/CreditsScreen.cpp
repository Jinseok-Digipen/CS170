#include "CreditsScreen.h"

#include "Game.h"
#include "SceneDrawing.h"


#include <doodle/drawing.hpp>
#include <doodle/environment.hpp>
#include <iostream>

CreditsScreen::CreditsScreen(Game& the_game)
    : mainMenu(doodle::Width / 2.0, doodle::Height - 50.0, "Main Menu"), Scene(the_game)
{
}

void CreditsScreen::Update()
{
    if (mainMenu.DidClickButton())
    {
        std::cout << "Main Menu!\n";
        Scene::game().QueueNextScene(GameScenes::MAIN_MENU);
    }
}

void CreditsScreen::Draw() const
{
    Draw_Title("Credits");

    doodle::push_settings();
    doodle::set_font_size(20);
    doodle::set_fill_color(0);
    doodle::no_outline();
    doodle::set_font_backdrop_fade_out_interval(0.5, 0.55);
    doodle::draw_text("Made by Rudy Castan", doodle::Width / 2.0, doodle::Height / 2.0);
    doodle::pop_settings();

    mainMenu.Draw();
}

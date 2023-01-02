// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#include "Button.h"

#include <doodle/drawing.hpp>
#include <doodle/input.hpp>


using namespace doodle;


Button::Button(double center_x, double center_y, const std::string& button_label)
    : left(center_x - WIDTH / 2.0), top(center_y - HEIGHT / 2.0), label(button_label)
{
}

void Button::Draw() const
{
    push_settings();
    set_frame_of_reference(FrameOfReference::LeftHanded_OriginTopLeft);
    set_outline_color(159);
    double fill_color   = 220;
    double label_offset = 0;
    if (this->mouseIsOver)
    {
        if (doodle::MouseIsPressed)
        {
            fill_color   = 200;
            label_offset = 1;
        }
        else
        {
            fill_color = 240;
        }
    }
    set_fill_color(fill_color);
    apply_translate(this->left, this->top);
    draw_rectangle(0, 0, WIDTH, HEIGHT);

    set_fill_color(0);
    no_outline();
    set_font_size(10);
    set_font_backdrop_fade_out_interval(0.7, 0.7);
    draw_text(this->label, WIDTH / 8.0, HEIGHT * 0.75 + label_offset);

    pop_settings();
}

bool Button::DidClickButton()
{
    const auto the_left   = this->left;
    const auto the_top    = this->top;
    const auto the_right  = the_left + WIDTH;
    const auto the_bottom = the_top + HEIGHT;
    push_settings();
    set_frame_of_reference(FrameOfReference::LeftHanded_OriginTopLeft);
    const double mouse_x = doodle::get_mouse_x();
    const double mouse_y = doodle::get_mouse_y();
    pop_settings();

    const bool within_x   = mouse_x > the_left && mouse_x < the_right;
    const bool within_y   = mouse_y > the_top && mouse_y < the_bottom;
    mouseIsOver           = within_x && within_y;
    const bool clicked_it = mouseIsOver && mouseWasPressed && !doodle::MouseIsPressed;
    mouseWasPressed       = doodle::MouseIsPressed;

    return clicked_it;
}

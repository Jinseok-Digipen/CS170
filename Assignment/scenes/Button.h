// Name       : Rudy
// Assignment : Scenes to OOP
// Course     : CS170
// Term & Year: Spring 2021
#pragma once

#include <string>

class Button
{
    constexpr static double WIDTH  = 100;
    constexpr static double HEIGHT = 35;

    double      left{ -WIDTH / 2 };
    double      top{ -HEIGHT / 2 };
    std::string label{ "Click Me" };
    bool        mouseIsOver     = false;
    bool        mouseWasPressed = false;

public:
    Button() = default;
    Button(double center_x, double center_y, const std::string& button_label);

    void Draw() const;

    bool DidClickButton();
};

#include "Vec2.h"
#include <doodle/doodle.hpp>

using namespace doodle;

namespace math
{
    using point2 = vec2;
}

int main(void)
{
    create_window("Math Demo - Press Spacebar");

    constexpr int max_square_count = 20 * 2;
    int           square_count     = 3;
    double        angle            = 0;

    set_callback_key_released([&](KeyboardButtons button) {
        if (button == KeyboardButtons::Space)
        {
            square_count = 1 + square_count % max_square_count;
            set_window_title("Square Dimension: " + std::to_string(square_count) + "/" +
                             std::to_string(max_square_count));
        }
    });

    while (!is_window_closed())
    {
        update_window();
        clear_background(240, 180);

        const double t             = noise(ElapsedTime * 0.5);
        const double display_scale = t * t * 0.6 + 0.3;
        const double offset_scale  = (1.0 - display_scale) * 0.5;
        const double full_width    = std::min(Width, Height) * 0.8;
        const double step          = full_width / square_count;
        const double rotation_rate = -(TWO_PI / (t * t * 50.0 + 1.0));
        angle += rotation_rate * DeltaTime;
        {
            push_settings();
            no_fill();
            set_outline_width(3);
            set_rectangle_mode(RectMode::Center);
            apply_rotate(angle);

            math::point2     starting_point{-full_width * 0.5};
            const math::vec2 right{step, 0};
            const math::vec2 up{0, step};
            const math::vec2 scaled_offset{step * offset_scale};
            const math::vec2 display_size = (right + up) * display_scale;
            for (int i = 0; i < square_count; ++i)
            {
                starting_point.y = -full_width * 0.5;
                for (int j = 0; j < square_count; ++j)
                {
                    set_outline_color(255.0 * i / square_count,255.0 * j / square_count,80);
                    const double       s1           = noise(i * 0.3, j, ElapsedTime);
                    const double       s2           = noise(i * 0.1, j * .1, ElapsedTime * 0.5);
                    const math::vec2   dimensions   = (0.7 + s1 * 0.5) * display_size;
                    const math::vec2   noise_offset = (s2 * 2.0 - 1.0) * dimensions;
                    const math::point2 bottom_left  = starting_point + scaled_offset + 0.5 * dimensions + noise_offset;
                    {
                        push_settings();
                        apply_translate(bottom_left.x, bottom_left.y);
                        apply_rotate(s2 * 4.0 * PI * t);
                        apply_scale(dimensions.x, dimensions.y);
                        draw_rectangle(0, 0, 1.0);
                        pop_settings();
                    }
                    starting_point += up;
                }
                starting_point += right;
            }
            pop_settings();
        }
    }
    return 0;
}

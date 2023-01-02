#include "MathTraits.h"
#include "../Vec2/Vec2.h"

#include <ios>
#include <iostream>

constexpr void vec2_traits_check() noexcept
{
    using namespace std;
    static_assert(math::has_x<math::vec2>::value, "Has Simple x field access");
    static_assert(math::has_y<math::vec2>::value, "Has Simple y field access");
    static_assert(is_standard_layout<math::vec2>::value, "Has standard layout of Plain Old Data");

    // Construction tests
    static_assert(is_default_constructible<math::vec2>::value, "Is default-constructable");
    static_assert(is_nothrow_default_constructible<math::vec2>::value, "Is nothrow default-constructable");
    static_assert(is_nothrow_constructible<math::vec2, double>::value, "Can construct from one double");
    static_assert(is_nothrow_constructible<math::vec2, double, double>::value, "Can construct from two doubles");
    static_assert(is_nothrow_copy_constructible<math::vec2>::value, "Has noexcept Copy Constructor");
    static_assert(is_nothrow_move_constructible<math::vec2>::value, "Has noexcept Move Constructor");
    static_assert(is_nothrow_destructible<math::vec2>::value, "Has noexcept Destructor");

    // Comparison tests
    static_assert(math::has_equals_comparison<math::vec2>::value, "Can do v1 == v2");
    static_assert(math::has_not_equals_comparison<math::vec2>::value, "Can do v1 != v2");

    // Assignment
    static_assert(is_nothrow_copy_assignable<math::vec2>::value, "Has noexcept Copy Assignment operator");
    static_assert(is_nothrow_move_assignable<math::vec2>::value, "Has noexcept Move Assignment operator");

    // Addition / Subtraction
    static_assert(math::has_plus_operator<math::vec2>::value, "Can do v + v");
    static_assert(math::has_plus_assignment_operator<math::vec2>::value, "Can do v += v");
    static_assert(math::has_minus_operator<math::vec2>::value, "Can do v - v");
    static_assert(math::has_minus_assignment_operator<math::vec2>::value, "Can do v -= v");

    // Negation operator
    static_assert(math::has_negation_operator<math::vec2>::value, "can do -v");

    // Scale Operations
    static_assert(math::can_multiply_together<double, math::vec2, math::vec2>::value, "Number * Vector => Vector");
    static_assert(math::can_multiply_together<math::vec2, double, math::vec2>::value, "Vector * Number => Vector");
    static_assert(math::can_multiply_assignment_operator<math::vec2, double>::value, "Vector *= Number");
    static_assert(!math::can_divide_together<double, math::vec2, math::vec2>::value,
                  "Number / Vector => Doesn't make sense");
    static_assert(math::can_divide_together<math::vec2, double, math::vec2>::value, "Vector / Number => Vector");
    static_assert(math::can_divide_assignment_operator<math::vec2, double>::value, "Vector /= Number");

    // len^2 and |v|
    static_assert(math::has_lengthsquared<math::vec2>::value, "Has a LengthSquared() method");
    static_assert(math::has_normalize<math::vec2>::value, "Has a Normalize() method");
}

constexpr math::vec2 get_zero_with_plus_assignment()
{
    math::vec2 zero{1.0};
    zero += math::vec2{-1.0};
    return zero;
}

constexpr math::vec2 get_two_with_minus_assignment()
{
    math::vec2 two{1.0};
    two -= math::vec2{-1.0};
    return two;
}

constexpr math::vec2 get_five_with_times_assignment()
{
    math::vec2 five{10.0};
    five *= 0.5;
    return five;
}

constexpr math::vec2 get_seven_with_divide_assignment()
{
    math::vec2 seven{3.5};
    seven /= 0.5;
    return seven;
}

constexpr void vec2_implementation_check() noexcept
{
    constexpr auto epsilon = std::numeric_limits<double>::epsilon();

    // Constructors
    {
        constexpr math::vec2 default_ctor;
        static_assert(default_ctor.x == 0.0 && default_ctor.y == 0.0, "should default to {0,0}");

        constexpr math::vec2 fill_float_curly{2.0};
        static_assert(fill_float_curly.x == 2.0 && fill_float_curly.y == 2.0, "should construct to {2,2}");

        constexpr math::vec2 custom_xy_curly{1.0, 2.0};
        static_assert(custom_xy_curly.x == 1.0 && custom_xy_curly.y == 2.0, "should construct to {1,2}");
    }

    // Comparisons
    {
        constexpr math::vec2 one_two = {1.0f, 2.0f};
        static_assert(one_two == math::vec2(1.0f + epsilon, 2.0f + epsilon), "numbers close together should be equal");
        static_assert(one_two != math::vec2(2.0, 1.0f), "different numbers should not be the same");
        static_assert(one_two == math::vec2(1.0, 2.0f), "same numbers should be the same");

        constexpr math::vec2 A{1};
        constexpr math::vec2 B(1);
        static_assert(!(A != B), "A != b");
        static_assert(A == B, "A == B");
    }

    {
        constexpr math::vec2 one{1.0};
        constexpr math::vec2 negative_one{-1.0};
        constexpr math::vec2 zero;
        static_assert((one + negative_one) == zero, "Test Plus");
    }
    {
        constexpr auto zero = get_zero_with_plus_assignment();
        static_assert(zero == math::vec2{0.0}, "Test Plus Assignment");
    }

    {
        constexpr math::vec2 one{1.0};
        constexpr math::vec2 negative_one{-1.0};
        constexpr math::vec2 two = one - negative_one;
        static_assert(two == math::vec2{2.0}, "Test Minus");
    }
    {
        constexpr math::vec2 two = get_two_with_minus_assignment();
        static_assert(two == math::vec2{2.0}, "Test Minus Assignment");
    }
    {
        constexpr math::vec2 ten{10.0};
        static_assert(-ten == math::vec2{-10}, "Test negation operator");
        static_assert(ten == math::vec2{10}, "Negation operator does not change instance");
    }
    {
        constexpr math::vec2 five = get_five_with_times_assignment();
        static_assert(five == math::vec2{5.0}, "[10,10]*=0.5 => [5,5]");

        constexpr math::vec2 ten_negthree = 2.0 * math::vec2{5.0, -1.5};
        static_assert(ten_negthree == math::vec2{10.0, -3.0}, "2*[5,-1.5] == [10,-3]");

        constexpr math::vec2 v_45_2_25 = math::vec2{30.0, 1.5} * 1.5;
        static_assert(v_45_2_25 == math::vec2{45.0, 2.25}, "[30,1.5]*1.5 == [45, 2.25]");

        constexpr math::vec2 seven = get_seven_with_divide_assignment();
        static_assert(seven == math::vec2{7.0}, "[3.5,3.5]/=0.5 => [7,7]");

        constexpr math::vec2 v_30_1_5 = math::vec2{45.0, 2.25} / 1.5;
        static_assert(v_30_1_5 == math::vec2{30.0, 1.5}, "[45,2.25] / 1.5 == [30,1.5]");
    }
    {
        constexpr double len = math::vec2{2.0, -3.0}.LengthSquared();
        static_assert(len == 13.0, "2^2+(-3)^2 == 13");
    }
}

constexpr void ivec2_traits_check() noexcept
{
    using namespace std;
    static_assert(math::has_x<math::ivec2>::value, "Has Simple x field access");
    static_assert(math::has_y<math::ivec2>::value, "Has Simple y field access");
    static_assert(is_standard_layout<math::ivec2>::value, "Has standard layout of Plain Old Data");

    // Construction tests
    static_assert(is_default_constructible<math::ivec2>::value, "Is default-constructable");
    static_assert(is_nothrow_default_constructible<math::ivec2>::value, "Is nothrow default-constructable");
    static_assert(is_nothrow_constructible<math::ivec2, int>::value, "Can construct from one integer");
    static_assert(is_nothrow_constructible<math::ivec2, int, int>::value, "Can construct from two integers");
    static_assert(is_nothrow_copy_constructible<math::ivec2>::value, "Has noexcept Copy Constructor");
    static_assert(is_nothrow_move_constructible<math::ivec2>::value, "Has noexcept Move Constructor");
    static_assert(is_nothrow_destructible<math::ivec2>::value, "Has noexcept Destructor");

    // Comparison tests
    static_assert(math::has_equals_comparison<math::ivec2>::value, "Can do v1 == v2");
    static_assert(math::has_not_equals_comparison<math::ivec2>::value, "Can do v1 != v2");

    // Assignment
    static_assert(is_nothrow_copy_assignable<math::ivec2>::value, "Has noexcept Copy Assignment operator");
    static_assert(is_nothrow_move_assignable<math::ivec2>::value, "Has noexcept Move Assignment operator");

    // Addition / Subtraction
    static_assert(math::has_plus_operator<math::ivec2>::value, "Can do v + v");
    static_assert(math::has_plus_assignment_operator<math::ivec2>::value, "Can do v += v");
    static_assert(math::has_minus_operator<math::ivec2>::value, "Can do v - v");
    static_assert(math::has_minus_assignment_operator<math::ivec2>::value, "Can do v -= v");

    // Negation operator
    static_assert(math::has_negation_operator<math::ivec2>::value, "can do -v");

    // Scale Operations
    static_assert(math::can_multiply_together<double, math::ivec2, math::vec2>::value, "double * ivec2 => vec2");
    static_assert(math::can_multiply_together<math::ivec2, double, math::vec2>::value, "ivec2 * double => vec2");
    static_assert(!math::can_divide_together<double, math::ivec2, math::ivec2>::value,
                  "Number / Vector => Doesn't make sense");
    static_assert(math::can_divide_together<math::ivec2, double, math::vec2>::value, "ivec2 / double => vec2");

    static_assert(math::can_multiply_together<int, math::ivec2, math::ivec2>::value, "int * Vector => Vector");
    static_assert(math::can_multiply_together<math::ivec2, int, math::ivec2>::value, "Vector * int => Vector");
    static_assert(math::can_multiply_assignment_operator<math::ivec2, int>::value, "Vector *= int");
    static_assert(!math::can_divide_together<int, math::ivec2, math::ivec2>::value,
                  "Number / Vector => Doesn't make sense");
    static_assert(math::can_divide_together<math::ivec2, int, math::ivec2>::value, "Vector / int => Vector");
    static_assert(math::can_divide_assignment_operator<math::ivec2, int>::value, "Vector /= int");
}

constexpr math::ivec2 get_zero_with_plus_assignment_ivec2()
{
    math::ivec2 zero{1};
    zero += math::ivec2{-1};
    return zero;
}

constexpr math::ivec2 get_two_with_minus_assignment_ivec2()
{
    math::ivec2 two{1};
    two -= math::ivec2{-1};
    return two;
}

constexpr math::ivec2 get_five_with_times_assignment_ivec2()
{
    math::ivec2 five{5};
    five *= 1;
    return five;
}

constexpr math::ivec2 get_seven_with_divide_assignment_ivec2()
{
    math::ivec2 seven{14};
    seven /= 2;
    return seven;
}

constexpr void ivec2_implementation_check() noexcept
{
    constexpr auto epsilon = std::numeric_limits<double>::epsilon();

    // Constructors
    {
        constexpr math::ivec2 default_ctor;
        static_assert(default_ctor.x == 0 && default_ctor.y == 0, "should default to {0,0}");

        constexpr math::ivec2 fill_float_curly{2};
        static_assert(fill_float_curly.x == 2 && fill_float_curly.y == 2, "should construct to {2,2}");

        constexpr math::ivec2 custom_xy_curly{1, 2};
        static_assert(custom_xy_curly.x == 1 && custom_xy_curly.y == 2, "should construct to {1,2}");
    }

    // Comparisons
    {
        constexpr math::ivec2 one_two = {1, 2};
        static_assert(one_two != math::ivec2(2, 1), "different numbers should not be the same");
        static_assert(one_two == math::ivec2(1, 2), "same numbers should be the same");

        constexpr math::ivec2 A{1};
        constexpr math::ivec2 B(1);
        static_assert(!(A != B), "A != b");
        static_assert(A == B, "A == B");
    }

    {
        constexpr math::ivec2 one{1};
        constexpr math::ivec2 negative_one{-1};
        constexpr math::ivec2 zero;
        static_assert((one + negative_one) == zero, "Test Plus");
    }
    {
        constexpr auto zero = get_zero_with_plus_assignment_ivec2();
        static_assert(zero == math::ivec2{0}, "Test Plus Assignment");
    }

    {
        constexpr math::ivec2 one{1};
        constexpr math::ivec2 negative_one{-1};
        constexpr math::ivec2 two = one - negative_one;
        static_assert(two == math::ivec2{2}, "Test Minus");
    }
    {
        constexpr math::ivec2 two = get_two_with_minus_assignment_ivec2();
        static_assert(two == math::ivec2{2}, "Test Minus Assignment");
    }
    {
        constexpr math::ivec2 ten{10};
        static_assert(-ten == math::ivec2{-10}, "Test negation operator");
        static_assert(ten == math::ivec2{10}, "Negation operator does not change instance");
    }
    {
        constexpr math::ivec2 five = get_five_with_times_assignment_ivec2();
        static_assert(five == math::ivec2{5}, "[5,5]*=1 => [5,5]");

        constexpr math::ivec2 ten_negthree = 1 * math::ivec2{10, -3};
        static_assert(ten_negthree == math::ivec2{10, -3}, "1*[10,-3] == [10,-3]");

        constexpr math::ivec2 v_45_2_25 = math::ivec2{45, 2} * 1;
        static_assert(v_45_2_25 == math::ivec2{45, 2}, "[45,2]*1 == [45, 2]");

        constexpr math::ivec2 seven = get_seven_with_divide_assignment_ivec2();
        static_assert(seven == math::ivec2{7}, "[14,14]/=2 => [7,7]");

        constexpr math::ivec2 v_30_5 = math::ivec2{30, 5} / 1;
        static_assert(v_30_5 == math::ivec2{30, 5}, "[30,5] / 1 == [30,5]");
    }

    {
        constexpr math::vec2 ten_negthree = 1.0 * math::ivec2{10, -3};
        static_assert(ten_negthree == math::vec2{10.0, -3.0}, "1.0*[10,-3] == [10.0,-3.0]");

        constexpr math::vec2 v_45_2_25 = math::ivec2{45, 2} * 1.0;
        static_assert(v_45_2_25 == math::vec2{45.0, 2.0}, "[45,2]*1.0 == [45.0, 2.0]");

        constexpr math::vec2 v_30_5 = math::ivec2{30, 5} / 1.0;
        static_assert(v_30_5 == math::vec2{30.0, 5.0}, "[30,5] / 1.0 == [30.0,5.0]");
    }
}

int main()
{
    vec2_traits_check();
    ivec2_traits_check();

    vec2_implementation_check();
    ivec2_implementation_check();

    std::cout << std::boolalpha;

    const auto one = math::vec2{3.0, 4.0}.Normalize();
    std::cout << "Normalized [3,4]? : " << (one == math::vec2{0.6,0.8}) << '\n';

    return 0;
}

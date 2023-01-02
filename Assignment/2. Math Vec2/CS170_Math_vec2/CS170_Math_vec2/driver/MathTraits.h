#pragma once

#include <type_traits>

namespace math
{
    using false_type = std::false_type;
    using true_type  = std::true_type;
    using std::declval;
    template <typename T>
    using void_t = void;


    template <typename VEC2, typename = void>
    struct has_x : false_type
    {
    };

    template <typename VEC2>
    struct has_x<VEC2, void_t<decltype(declval<VEC2>().x)>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_y : false_type
    {
    };

    template <typename VEC2>
    struct has_y<VEC2, void_t<decltype(declval<VEC2>().y)>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_equals_comparison : false_type
    {
    };

    template <typename VEC2>
    struct has_equals_comparison<VEC2, void_t<decltype(declval<VEC2>() == declval<VEC2>())>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_not_equals_comparison : false_type
    {
    };

    template <typename VEC2>
    struct has_not_equals_comparison<VEC2, void_t<decltype(declval<VEC2>() != declval<VEC2>())>> : true_type
    {
    };

    template <typename T, typename U, typename = void>
    struct can_equals_comparison : false_type
    {
    };

    template <typename T, typename U>
    struct can_equals_comparison<T, U, void_t<decltype(declval<T>() == declval<U>())>> : true_type
    {
    };

    template <typename T, typename U, typename = void>
    struct can_not_equals_comparison : false_type
    {
    };

    template <typename T, typename U>
    struct can_not_equals_comparison<T, U, void_t<decltype(declval<T>() != declval<U>())>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_plus_operator : false_type
    {
    };

    template <typename VEC2>
    struct has_plus_operator<VEC2, void_t<decltype(declval<VEC2>() + declval<VEC2>())>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_plus_assignment_operator : false_type
    {
    };

    template <typename VEC2>
    struct has_plus_assignment_operator<VEC2, void_t<decltype(declval<VEC2&>() += declval<VEC2>())>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_minus_operator : false_type
    {
    };

    template <typename VEC2>
    struct has_minus_operator<VEC2, void_t<decltype(declval<VEC2>() - declval<VEC2>())>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_minus_assignment_operator : false_type
    {
    };

    template <typename VEC2>
    struct has_minus_assignment_operator<VEC2, void_t<decltype(declval<VEC2&>() -= declval<VEC2>())>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_lengthsquared : false_type
    {
    };

    template <typename VEC2>
    struct has_lengthsquared<VEC2, void_t<decltype(declval<VEC2&>().LengthSquared())>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_normalize : false_type
    {
    };

    template <typename VEC2>
    struct has_normalize<VEC2, void_t<decltype(declval<VEC2&>().Normalize())>> : true_type
    {
    };

    template <typename T, typename U, typename RETURN = void, typename = void>
    struct can_subtract_together : false_type
    {
    };

    template <typename T, typename U, typename RETURN>
    struct can_subtract_together<T, U, RETURN, void_t<decltype(declval<RETURN>() = declval<T>() - declval<U>())>>
        : true_type
    {
    };

    template <typename T, typename U>
    struct can_subtract_together<T, U, void, void_t<decltype(declval<T>() - declval<U>())>> : true_type
    {
    };

    template <typename T, typename U, typename RETURN = void, typename = void>
    struct can_add_together : false_type
    {
    };

    template <typename T, typename U, typename RETURN>
    struct can_add_together<T, U, RETURN, void_t<decltype(declval<RETURN>() = declval<T>() + declval<U>())>> : true_type
    {
    };

    template <typename T, typename U>
    struct can_add_together<T, U, void, void_t<decltype(declval<T>() + declval<U>())>> : true_type
    {
    };

    template <typename T, typename U, typename = void>
    struct can_minus_assignment_operator : false_type
    {
    };

    template <typename T, typename U>
    struct can_minus_assignment_operator<T, U, void_t<decltype(declval<T&>() -= declval<U>())>> : true_type
    {
    };

    template <typename T, typename U, typename = void>
    struct can_plus_assignment_operator : false_type
    {
    };

    template <typename T, typename U>
    struct can_plus_assignment_operator<T, U, void_t<decltype(declval<T&>() += declval<U>())>> : true_type
    {
    };

    template <typename VEC2, typename = void>
    struct has_negation_operator : false_type
    {
    };

    template <typename VEC2>
    struct has_negation_operator<VEC2, void_t<decltype(-declval<VEC2>())>> : true_type
    {
    };

    template <typename T, typename U, typename RETURN = void, typename = void>
    struct can_multiply_together : false_type
    {
    };

    template <typename T, typename U, typename RETURN>
    struct can_multiply_together<T, U, RETURN, void_t<decltype(declval<RETURN>() = declval<T>() * declval<U>())>>
        : true_type
    {
    };

    template <typename T, typename U>
    struct can_multiply_together<T, U, void, void_t<decltype(declval<T>() * declval<U>())>> : true_type
    {
    };

    template <typename T, typename U, typename = void>
    struct can_multiply_assignment_operator : false_type
    {
    };

    template <typename T, typename U>
    struct can_multiply_assignment_operator<T, U, void_t<decltype(declval<T&>() *= declval<U>())>> : true_type
    {
    };

    template <typename T, typename U, typename RETURN = void, typename = void>
    struct can_divide_together : false_type
    {
    };

    template <typename T, typename U, typename RETURN>
    struct can_divide_together<T, U, RETURN, void_t<decltype(declval<RETURN>() = declval<T>() / declval<U>())>>
        : true_type
    {
    };

    template <typename T, typename U>
    struct can_divide_together<T, U, void, void_t<decltype(declval<T>() / declval<U>())>> : true_type
    {
    };

    template <typename T, typename U, typename = void>
    struct can_divide_assignment_operator : false_type
    {
    };

    template <typename T, typename U>
    struct can_divide_assignment_operator<T, U, void_t<decltype(declval<T&>() /= declval<U>())>> : true_type
    {
    };
}

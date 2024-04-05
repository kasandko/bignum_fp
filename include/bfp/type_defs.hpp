#ifndef _BFP_TYPE_DEFS_H_
#define _BFP_TYPE_DEFS_H_

#include <ex_type_traits/op_traits.h>
#include <type_traits>
#include <cstdint>
#include <cassert>
#include <utility>

namespace bfp {

using LenType = int16_t;

template <typename T>
inline constexpr bool is_convertible_to_integer_v =
    std::is_convertible_v<T, char> &&
    std::is_convertible_v<T, wchar_t> &&
    std::is_convertible_v<T, int8_t> &&
    std::is_convertible_v<T, uint8_t> &&
    std::is_convertible_v<T, int16_t> &&
    std::is_convertible_v<T, uint16_t> &&
    std::is_convertible_v<T, int32_t> &&
    std::is_convertible_v<T, uint32_t> &&
    std::is_convertible_v<T, int64_t> &&
    std::is_convertible_v<T, uint64_t>;

// Asserts block. Places of use of the operator being checked are marked "#assert:N" where
    // N - number of static_assert.
template <typename TBase, typename TPromotion>
struct base_type_asserts
{
    using base_type = TBase;
    using promotion_type = TPromotion;

    // #assert:1.
    static_assert(exttr::op::is_b_lshiftable_v<base_type, base_type, size_t>, "Base type can not support <<.");

    // #assert:2.
    static_assert(exttr::op::is_b_subtractive_v<base_type, base_type, int>, "Base type can not support - with int.");

    // #assert:3.
    static_assert(exttr::op::is_bit_inversible_v<base_type, base_type>, "Base type can not support ~.");

    // #assert:4.
    static_assert(exttr::op::is_a_lshiftable_v<base_type, size_t>, "Base type can not support <<=.");

    // #assert:5.
    static_assert(exttr::op::is_a_rshiftable_v<base_type, size_t>, "Base type can not support >>=.");

    // #assert:6.
    static_assert(std::is_constructible_v<base_type, base_type &>, "Base type can not support copy constructor.");

    // #assert:7.
    static_assert(std::is_assignable_v<base_type &, base_type>, "Base type can not support assignable constructor.");

    // #assert:8.
    static_assert(exttr::op::is_lss_v<base_type, base_type>, "Base type is not comparable.");

    // #assert:9.
    static_assert(exttr::op::is_equ_v<base_type, base_type>, "Base type is not comparable.");

    // #assert:10.
    static_assert(exttr::op::is_equ_v<base_type, int>, "Base type is not comparable with int.");

    // #assert:11.
    static_assert(std::is_signed_v<base_type> && exttr::op::is_negativable_v<base_type, base_type>, "Signed base type can not support unary -.");

    // #assert:12.
    static_assert(exttr::op::is_a_summative_v<base_type&, base_type>, "Base type can not support +=.");

    // #assert:13.
    static_assert(exttr::op::is_a_subtractive_v<base_type&, base_type>, "Base type can not support -=.");

    // #assert:14.
    static_assert(std::is_constructible_v<promotion_type, base_type &>, "Promotion type can not construct with base type.");

    // #assert:15.
    static_assert(exttr::op::is_b_multiplicative_v<promotion_type, promotion_type, base_type &>, "Promotion type can not be multiplication with base type.");

    // #assert:16.
    static_assert(exttr::op::is_b_rshiftable_v<promotion_type, promotion_type, size_t>, "Promotion type can not support >>.");

    // #assert:17.
    static_assert(std::is_constructible_v<base_type, promotion_type &>, "Base type can not construct with promotion type.");

    // #assert:18.
    static_assert(exttr::op::is_b_lshiftable_v<promotion_type, promotion_type, size_t>, "Promotion type can not support <<.");

    // #assert:19.
    static_assert(exttr::op::is_b_dividable_v<promotion_type, promotion_type, base_type &>, "Promotion type can not be division by base type.");

    // #assert:20.
    static_assert(is_convertible_to_integer_v<base_type>, "Base type can not convert to any standard integer type.");

    // #assert:21.
    static_assert( std::is_convertible_v<base_type, bool>, "Base type can not convert to bool.");

    // #assert:22.
    static_assert(exttr::op::is_b_rshiftable_v<base_type, base_type, size_t>, "Base type can not support >>.");

    // #assert:23.
    static_assert(exttr::op::is_b_bit_conjunctionable_v<base_type, base_type, base_type &>, "Base type can not support &.");
};

} // namespace bfp

#endif // _BFP_TYPE_DEFS_H_

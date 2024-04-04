#ifndef _BFP_TYPE_DEFS_H_
#define _BFP_TYPE_DEFS_H_

#include <ex_type_traits/op_traits.h>
#include <type_traits>
#include <cstdint>
#include <cassert>
#include <utility>

namespace bfp {

using LenType = int16_t;

// Asserts block. Places of use of the operator being checked are marked "#assert:N" where
    // N - number of static_assert.
template <typename TBase>
struct base_type_asserts
{
    using base_type = TBase;

    // #assert:1.
    static_assert(exttr::op::is_b_lshiftable_v<base_type, base_type, LenType>, "Base type can not support <<.");

    // #assert:2.
    static_assert(exttr::op::is_b_subtractive_v<base_type, base_type, int>, "Base type can not support - with int.");

    // #assert:3.
    static_assert(exttr::op::is_bit_inversible_v<base_type, base_type>, "Base type can not support ~.");

    // #assert:4.
    static_assert(exttr::op::is_a_lshiftable_v<base_type, LenType>, "Base type can not support <<=.");

    // #assert:5.
    static_assert(exttr::op::is_a_rshiftable_v<base_type, LenType>, "Base type can not support >>=.");

    // #assert:6.
    // static_assert(, "Base type can not support copy constructor."); // TODO:

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
};

} // namespace bfp

#endif // _BFP_TYPE_DEFS_H_

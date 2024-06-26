/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief 
 *
 *************************************************************************************************/

#ifndef _BFP_STREAM_HPP_
#define _BFP_STREAM_HPP_

#include <istream>
#include <ostream>
#include <bfp/fixed.hpp>

#ifdef BFP_GLOBAL_STREAM_OVERLOAD
    #define BFP_NS_START
    #define BFP_NS_END
#else
    #define BFP_NS_START namespace bfp {
    #define BFP_NS_END }
#endif

namespace bfp {

namespace internal { // TODO: Move to some internal hpp file.

template <typename TStream>
struct is_valid_istream
{
    static inline constexpr bool value =
        std::is_base_of_v<std::istream, TStream> ||
        std::is_base_of_v<std::wistream, TStream>;
};

template <typename TStream>
struct is_valid_ostream
{
    static inline constexpr bool value =
        std::is_base_of_v<std::ostream, TStream> ||
        std::is_base_of_v<std::wostream, TStream>;
};

} // namespace internal
} // namespace bfp

BFP_NS_START

template<typename S, typename TBase, bfp::LenType Fractional, typename TBaseTypeTrait>
S & operator >> (S & s, bfp::fixed<TBase, Fractional, TBaseTypeTrait> & v)
{
    static_assert(bfp::internal::is_valid_istream<S>::value, "Invalid input stream.");

    _BFP_NOT_IMPLEMENTED_ASSERT
    // TODO: Implementation.
}

template<typename S, typename TBase, bfp::LenType Fractional, typename TBaseTypeTrait>
S & operator << (S & s, const bfp::fixed<TBase, Fractional, TBaseTypeTrait> & v)
{
    static_assert(bfp::internal::is_valid_ostream<S>::value, "Invalid output stream.");

    _BFP_NOT_IMPLEMENTED_ASSERT
    // TODO: Implementation.
}

BFP_NS_END

#endif // _BFP_STREAM_HPP_

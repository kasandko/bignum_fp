/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief 
 *
 *************************************************************************************************/

#ifndef _BFP_STRING_CVT_HPP_
#define _BFP_STRING_CVT_HPP_

#include <string>
#include <bfp/fixed.hpp>

namespace bfp {

/// @brief 
/// @param str 
/// @param pos 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> stof(const std::string & str, size_t * pos = nullptr)
{
    _BFP_NOT_IMPLEMENTED_ASSERT
    // TODO: Implementation.
}

/// @brief 
/// @param str 
/// @param pos 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> stof(const std::wstring & str, size_t * pos = nullptr)
{
    _BFP_NOT_IMPLEMENTED_ASSERT
    // TODO: Implementation.
}

/// @brief 
/// @param v 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
std::string to_string(const fixed<TBase, Fractional, TBaseTypeTrait> & v)
{
    _BFP_NOT_IMPLEMENTED_ASSERT
    // TODO: Implementation.
}

/// @brief 
/// @param v 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
std::wstring to_wstring(const fixed<TBase, Fractional, TBaseTypeTrait> & v)
{
    _BFP_NOT_IMPLEMENTED_ASSERT
    // TODO: Implementation.
}

} // namespace bfp

#endif // _BFP_STRING_CVT_HPP_

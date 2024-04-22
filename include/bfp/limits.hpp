/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief This file implemented C numeric limits interface for `fixed`.
 * 
 * This file contains constants which are similar constants from
 * [`<cfloat>`](https://en.cppreference.com/w/cpp/types/climits#Limits_of_floating-point_types)
 * but but doesn't match it completely. C numeric limits constants are presented as preprocessor
 * constants but this can not be implemented for `fixed` because this file contains template
 * constants.
 * 
 * @note This file is not recommended for use. All this constants are repeated in
 * `numeric_limits.hpp`.
 *************************************************************************************************/

#ifndef _BFP_LIMITS_HPP_
#define _BFP_LIMITS_HPP_

#include <bfp/numeric_limits.hpp>
#include <cfenv>

namespace bfp {

/// @brief 
///
///
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_RADIX = numeric_limits<TBase, Fractional, TBaseTypeTrait>::radix;

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_DECIMAL_DIG = numeric_limits<TBase, Fractional, TBaseTypeTrait>::max_digits10;

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr fixed<TBase, Fractional, TBaseTypeTrait> BFP_MIN = numeric_limits<TBase, Fractional, TBaseTypeTrait>::min();

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr fixed<TBase, Fractional, TBaseTypeTrait> BFP_TRUE_MIN = numeric_limits<TBase, Fractional, TBaseTypeTrait>::denorm_min();

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr fixed<TBase, Fractional, TBaseTypeTrait> BFP_MAX = numeric_limits<TBase, Fractional, TBaseTypeTrait>::max();

/// @brief 
///  
///
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr fixed<TBase, Fractional, TBaseTypeTrait> BFP_EPSILON = numeric_limits<TBase, Fractional, TBaseTypeTrait>::epsilon();

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_DIG = numeric_limits<TBase, Fractional, TBaseTypeTrait>::digits10;

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_MANT_DIG = numeric_limits<TBase, Fractional, TBaseTypeTrait>::digits;

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_MIN_EXP = numeric_limits<TBase, Fractional, TBaseTypeTrait>::min_exponent;

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_MIN_10_EXP = numeric_limits<TBase, Fractional, TBaseTypeTrait>::min_exponent10;

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_MAX_EXP =  = numeric_limits<TBase, Fractional, TBaseTypeTrait>::max_exponent;

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_MAX_10_EXP =  = numeric_limits<TBase, Fractional, TBaseTypeTrait>::max_exponent10;

/// @brief 
///  
///
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_ROUNDS = FE_TOWARDZERO;

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_EVAL_METHOD = 0;

/// @brief 
///  
/// 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
constexpr int BFP_HAS_SUBNORM = 0;

} // namespace bfp

#endif // _BFP_LIMITS_HPP_

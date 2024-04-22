/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief This file implements mathematical functions for `fixed`.
 * 
 *************************************************************************************************/

#ifndef _BFP_MATH_HPP_
#define _BFP_MATH_HPP_

#include <bfp/fixed.hpp>

namespace bfp {

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Basic operations
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fabs(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fmod(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> remainder(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief 
/// @param x 
/// @param y 
/// @param quo 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> remquo(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y,
    int * quo
);

/// @brief 
/// @param x 
/// @param y 
/// @param z 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fma(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y,
    const fixed<TBase, Fractional, TBaseTypeTrait> & z
);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fmax(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fmin(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief  
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fdim(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Linear interpolation
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param a 
/// @param b 
/// @param t 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> lerp(
    const fixed<TBase, Fractional, TBaseTypeTrait> & a,
    const fixed<TBase, Fractional, TBaseTypeTrait> & b,
    const fixed<TBase, Fractional, TBaseTypeTrait> & t
);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Exponential functions
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> exp(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> exp2(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> expml(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> log(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> log10(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> loglp(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Power functions
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param base 
/// @param exp 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> pow(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    const fixed<TBase, Fractional, TBaseTypeTrait> & exp
);

/// @brief 
/// @param base 
/// @param exp 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> pow(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> sqrt(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> cbrt(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> hypot(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief  
/// @param x 
/// @param y 
/// @param z 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> hypot(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y,
    const fixed<TBase, Fractional, TBaseTypeTrait> & z
);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Trigonometric functions
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> sin(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> cos(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> tan(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> asin(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> acos(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> atan(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> atan2(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Hyperbolic functions
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> sinh(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> cosh(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> tanh(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> asinh(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> acosh(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> atanh(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Error and gamma functions
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> erf(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> erfc(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> tgamma(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> lgamma(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Nearest integer floating-point operations
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> ceil(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> floor(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> trunc(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> round(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long lround(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long long llround(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> nearbyint(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> rint(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long lrint(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long long llrint(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Floating-point manipulation functions
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param base 
/// @param exp 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> frexp(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    int * exp
);

/// @brief 
/// @param base 
/// @param exp 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> ldexp(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
);

/// @brief 
/// @param num 
/// @param iptr 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> modf(
    const fixed<TBase, Fractional, TBaseTypeTrait> & num,
    fixed<TBase, Fractional, TBaseTypeTrait> * iptr
);

/// @brief 
/// @param base 
/// @param exp 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> scalbn(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
);

/// @brief 
/// @param base 
/// @param exp 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> scalbn(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    long exp
);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
int ilogb(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> logb(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param from 
/// @param to 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> nextafter(
    const fixed<TBase, Fractional, TBaseTypeTrait> & from,
    const fixed<TBase, Fractional, TBaseTypeTrait> & to
);

/// @brief 
/// @param mag 
/// @param sgn 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> copysign(
    const fixed<TBase, Fractional, TBaseTypeTrait> & mag,
    const fixed<TBase, Fractional, TBaseTypeTrait> & sgn
);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// # Classification and comparison
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
int fpclassify(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isfinite(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isinf(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isnan(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isnormal(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param num 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool signbit(const fixed<TBase, Fractional, TBaseTypeTrait> & num);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isgreater(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isgreaterequal(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isless(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool islessequal(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool islessgreater(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

/// @brief 
/// @param x 
/// @param y 
/// @return 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isunordered(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
);

} // namespace bfp

#endif // _BFP_MATH_HPP_

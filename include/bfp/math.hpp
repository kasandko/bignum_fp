#ifndef _BFP_MATH_HPP_
#define _BFP_MATH_HPP_

#include <bfp/fp.hpp>

namespace bfp {

///// Basic operations /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fabs(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fmod(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> remainder(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> remquo(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y,
    int * quo
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fma(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y,
    const fp<TBase, Fractional, TBaseTypeTrait> & z
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fmax(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fmin(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fdim(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

///// Linear interpolation /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> lerp(
    const fp<TBase, Fractional, TBaseTypeTrait> & a,
    const fp<TBase, Fractional, TBaseTypeTrait> & b,
    const fp<TBase, Fractional, TBaseTypeTrait> & t
)
{
    // TODO: Implementation.
}

///// Exponential functions /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> exp(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> exp2(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> expml(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> log(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> log10(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> loglp(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

///// Power functions /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> pow(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    const fp<TBase, Fractional, TBaseTypeTrait> & exp
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> pow(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> sqrt(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> cbrt(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> hypot(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> hypot(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y,
    const fp<TBase, Fractional, TBaseTypeTrait> & z
)
{
    // TODO: Implementation.
}

///// Trigonometric functions /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> sin(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> cos(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> tan(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> asin(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> acos(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> atan(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> atan2(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

///// Hyperbolic functions /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> sinh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> cosh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> tanh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> asinh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> acosh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> atanh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

///// Error and gamma functions /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> erf(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> erfc(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> tgamma(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> lgamma(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

///// Nearest integer floating-point operations /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> ceil(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> floor(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> trunc(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> round(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long lround(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long long llround(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> nearbyint(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> rint(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long lrint(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long long llrint(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

///// Floating-point manipulation functions /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> frexp(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    int * exp
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> ldexp(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> modf(
    const fp<TBase, Fractional, TBaseTypeTrait> & num,
    fp<TBase, Fractional, TBaseTypeTrait> * iptr
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> scalbn(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> scalbn(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    long exp
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
int ilogb(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> logb(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> nextafter(
    const fp<TBase, Fractional, TBaseTypeTrait> & from,
    const fp<TBase, Fractional, TBaseTypeTrait> & to
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> copysign(
    const fp<TBase, Fractional, TBaseTypeTrait> & mag,
    const fp<TBase, Fractional, TBaseTypeTrait> & sgn
)
{
    // TODO: Implementation.
}

///// Classification and comparison /////

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
int fpclassify(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isfinite(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isinf(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isnan(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isnormal(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool signbit(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isgreater(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isgreaterequal(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isless(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool islessequal(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool islessgreater(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isunordered(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    // TODO: Implementation.
}

} // namespace bfp

#endif // _BFP_MATH_HPP_

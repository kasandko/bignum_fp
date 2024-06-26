/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief 
 *
 *************************************************************************************************/

#ifndef _BFP_MATH_INL_
#define _BFP_MATH_INL_

#include <bfp/fixed.hpp>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <limits>

namespace bfp {

namespace internal {

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
inline const fixed<TBase, Fractional, TBaseTypeTrait> ZERO_VALUE = 0;

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
inline const fixed<TBase, Fractional, TBaseTypeTrait> ONE_VALUE = 1;

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
inline const fixed<TBase, Fractional, TBaseTypeTrait> HALF_ONE_VALUE = 0.5;

template <typename TIntResult, typename TBase, LenType Fractional, typename TBaseTypeTrait>
TIntResult _round(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    fixed_type result = round(num);
    fixed_type::base_type & base_result = result.data();
    base_result >>= fixed_type::fractional_bit_count;
    if (std::numeric_limits<TIntResult>::digits >= fixed_type::base_type_trait::limits::digits)
        return static_cast<TIntResult>(base_result);

    const fixed_type::base_type max_int =
        static_cast<fixed_type::base_type>(std::numeric_limits<TIntResult>::max());
    
    if (base_result > max_int)
    {
        errno = EDOM;
        std::feraiseexcept(FE_INVALID);
    }

    return static_cast<TIntResult>(base_result);
}

} // namespace internal

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fabs(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    return num < internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait> ? -num : num;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fmod(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    fixed_type result;
    result.data() = x.data() % y.data();
    return result;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> remainder(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    if (y == internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait>)
    {
        errno = EDOM;
        std::feraiseexcept(FE_INVALID);
        return 0;
    }

    const fixed_type r = x / y;
    const bool sgn = r > internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait>;

    fixed_type int_r = r;
    int_r.data() &= fixed_type::INTEGER_MASK;

    fixed_type next_int_r = int_r;
    if (sgn)
        ++next_int_r;
    else
        --next_int_r;

    fixed_type k1 = next_int_r - r;
    fixed_type k2 = r - int_r;

    if (!sgn)
    {
        k1.flip_sgn();
        k2.flip_sgn();
    }

    const fixed_type nearest = k1 < k2 ? next_int_r : int_r;
    return x - nearest * y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> remquo(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y,
    int * quo
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    const fixed_type rem = remainder(x, y);
    const fixed_type f_quo = x / y;
    quo = static_cast<int>(f_quo.data());

    return rem;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fma(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y,
    const fixed<TBase, Fractional, TBaseTypeTrait> & z
)
{
    return x * y + z;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fmax(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x > y ? x : y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fmin(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x < y ? x : y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> fdim(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x > y ? x - y : internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait>;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> lerp(
    const fixed<TBase, Fractional, TBaseTypeTrait> & a,
    const fixed<TBase, Fractional, TBaseTypeTrait> & b,
    const fixed<TBase, Fractional, TBaseTypeTrait> & t
)
{
    return a + t * (b - a);
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> exp(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> exp2(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> expml(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> log(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> log10(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> loglp(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> pow(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    const fixed<TBase, Fractional, TBaseTypeTrait> & exp
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> pow(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> sqrt(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> cbrt(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> hypot(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> hypot(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y,
    const fixed<TBase, Fractional, TBaseTypeTrait> & z
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> sin(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> cos(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> tan(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> asin(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> acos(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> atan(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> atan2(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> sinh(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> cosh(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> tanh(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> asinh(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> acosh(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> atanh(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> erf(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> erfc(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> tgamma(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> lgamma(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> ceil(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    fixed_type result;
    result.data() = num.data() & fixed_type::INTEGER_MASK;
    if (num.fract() > 0 && num > internal::ZERO_VALUE)
        ++result;

    return result;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> floor(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    fixed_type result;
    result.data() = num.data() & fixed_type::INTEGER_MASK;
    if (num.fract() > 0 && num < internal::ZERO_VALUE)
        --result;

    return result;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> trunc(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    fixed_type result;
    result.data() = num.data() & fixed_type::INTEGER_MASK;
    return result;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> round(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    fixed_type integer;
    const fixed_type fract = fabs(modf(num, &integer));
    if (fract < internal::HALF_ONE_VALUE)
        return integer;

    return num >= internal::ZERO_VALUE
        ? ++integer
        : --integer;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long lround(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    return internal::_round<long>(num);
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long long llround(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    return internal::_round<long long>(num);
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> nearbyint(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    const int round_type = std::fegetround();
    switch (round_type)
    {
    case FE_DOWNWARD:
        return floor(num);
    case FE_TONEAREST:
        return round(num);
    case FE_TOWARDZERO:
        return trunc(num);
    case FE_UPWARD:
        return ceil(num);
    default:
        return fixed_type();
    }
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> rint(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long lrint(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long long llrint(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> frexp(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    int * exp
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> ldexp(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> modf(
    const fixed<TBase, Fractional, TBaseTypeTrait> & num,
    fixed<TBase, Fractional, TBaseTypeTrait> * iptr
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    const bool less_zero = num < internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait>;

    fixed_type integer;
    integer.data() = num.data() & fixed_type::INTEGER_MASK;

    if (less_zero)
        ++integer;

    *iptr = integer;

    fixed_type fraction;
    fraction.data() = num.fract();

    return less_zero ? -fraction : fraction;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> scalbn(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> scalbn(
    const fixed<TBase, Fractional, TBaseTypeTrait> & base,
    long exp
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
int ilogb(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> logb(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> nextafter(
    const fixed<TBase, Fractional, TBaseTypeTrait> & from,
    const fixed<TBase, Fractional, TBaseTypeTrait> & to
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> copysign(
    const fixed<TBase, Fractional, TBaseTypeTrait> & mag,
    const fixed<TBase, Fractional, TBaseTypeTrait> & sgn
)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    return sgn >= internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait>
        ? mag : -mag;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
int fpclassify(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    return !num ? FP_ZERO : FP_NORMAL;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isfinite(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    return true;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isinf(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    return false;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isnan(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    return false;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isnormal(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    return !!num;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool signbit(const fixed<TBase, Fractional, TBaseTypeTrait> & num)
{
    return num > internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait>;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isgreater(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x > y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isgreaterequal(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x >= y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isless(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x < y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool islessequal(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x <= y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool islessgreater(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x != y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isunordered(
    const fixed<TBase, Fractional, TBaseTypeTrait> & x,
    const fixed<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return false;
}

} // namespace bfp

#endif // _BFP_MATH_INL_

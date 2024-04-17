#ifndef _BFP_MATH_INL_
#define _BFP_MATH_INL_

#include <bfp/fp.hpp>
#include <cmath>

namespace bfp {

namespace internal {

#undef _BFP_NOT_IMPLEMENTED_ASSERT
#define _BFP_NOT_IMPLEMENTED_ASSERT                 \
    assert("Not implemented.");                     \
    return {}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
inline const fp<TBase, Fractional, TBaseTypeTrait> ZERO_VALUE = 0;

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
inline const fp<TBase, Fractional, TBaseTypeTrait> ONE_VALUE = 1;

} // namespace internal

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fabs(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    return num < internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait> ? -num : num;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fmod(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    fp_type result;
    result.data() = x.data() % y.data();
    return result;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> remainder(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> remquo(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y,
    int * quo
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fma(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y,
    const fp<TBase, Fractional, TBaseTypeTrait> & z
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fmax(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fmin(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> fdim(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> lerp(
    const fp<TBase, Fractional, TBaseTypeTrait> & a,
    const fp<TBase, Fractional, TBaseTypeTrait> & b,
    const fp<TBase, Fractional, TBaseTypeTrait> & t
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> exp(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> exp2(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> expml(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> log(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> log10(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> loglp(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> pow(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    const fp<TBase, Fractional, TBaseTypeTrait> & exp
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> pow(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> sqrt(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> cbrt(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> hypot(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> hypot(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y,
    const fp<TBase, Fractional, TBaseTypeTrait> & z
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> sin(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> cos(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> tan(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> asin(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> acos(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> atan(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> atan2(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> sinh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> cosh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> tanh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> asinh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> acosh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> atanh(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> erf(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> erfc(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> tgamma(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> lgamma(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> ceil(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    fp_type result;
    result.data() = num.data() & fp_type::INTEGER_MASK;
    return result + fp_type(num.data() & fp_type::FRACTIONAL_MASK ? 1 : 0);
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> floor(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    fp_type result;
    result.data() = num.data() & fp_type::INTEGER_MASK;
    return result;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> trunc(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> round(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long lround(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long long llround(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> nearbyint(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> rint(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long lrint(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
long long llrint(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> frexp(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    int * exp
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> ldexp(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> modf(
    const fp<TBase, Fractional, TBaseTypeTrait> & num,
    fp<TBase, Fractional, TBaseTypeTrait> * iptr
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    const bool less_zero = num < internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait>;

    fp_type integer;
    integer.data() = num.data() & fp_type::INTEGER_MASK;
    *iptr = less_zero
        ? integer + internal::ONE_VALUE<TBase, Fractional, TBaseTypeTrait>
        : integer;

    fp_type fraction;
    fraction.data() = num.data() & fp_type::FRACTIONAL_MASK;

    return less_zero ? -fraction : fraction;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> scalbn(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    int exp
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> scalbn(
    const fp<TBase, Fractional, TBaseTypeTrait> & base,
    long exp
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
int ilogb(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> logb(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> nextafter(
    const fp<TBase, Fractional, TBaseTypeTrait> & from,
    const fp<TBase, Fractional, TBaseTypeTrait> & to
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> copysign(
    const fp<TBase, Fractional, TBaseTypeTrait> & mag,
    const fp<TBase, Fractional, TBaseTypeTrait> & sgn
)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    // TODO: Implementation.
    _BFP_NOT_IMPLEMENTED_ASSERT
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
int fpclassify(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    return !num ? FP_ZERO : FP_NORMAL;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isfinite(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    return true;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isinf(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    return false;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isnan(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    return false;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isnormal(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    return !!num;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool signbit(const fp<TBase, Fractional, TBaseTypeTrait> & num)
{
    return num > internal::ZERO_VALUE<TBase, Fractional, TBaseTypeTrait>;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isgreater(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x > y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isgreaterequal(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x >= y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isless(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x < y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool islessequal(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x <= y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool islessgreater(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return x != y;
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
bool isunordered(
    const fp<TBase, Fractional, TBaseTypeTrait> & x,
    const fp<TBase, Fractional, TBaseTypeTrait> & y
)
{
    return false;
}

} // namespace bfp

#endif // _BFP_MATH_INL_

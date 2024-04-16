#ifndef _BFP_FP_INL_
#define _BFP_FP_INL_

#include <bfp/fp.hpp>

namespace bfp {

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> &
    fp<TBase, Fractional, TBaseTypeTrait>::operator = (const internal::fp_number & fp_number)
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    const std::string src = fp_number._get_str();
    const size_t point_pos = fp_number._point_pos();

    const fp_type pow_factor(10);

    fp_type result(0);
    fp_type power(1);
    for (size_t power_v = 0u; power_v < point_pos; ++power_v)
    {
        const size_t idx = point_pos - power_v - 1u;

        if (power_v > 0u)
            power *= pow_factor;

        unsigned u_value = src[idx] - '0';
        result += fp_type(u_value) * power;
    }

    power(1);
    for (size_t idx = point_pos + 1u; idx < src.size(); ++idx)
    {
        power /= pow_factor;

        // If bottom overflow break calculation.
        if (!power)
            break;

        unsigned u_value = src[idx] - '0';
        result += fp_type(u_value) * power;
    }

    *this = result;
    return *this;
}

} // namespace bfp

#endif // _BFP_FP_INL_

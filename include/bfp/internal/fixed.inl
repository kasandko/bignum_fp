/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief 
 *
 *************************************************************************************************/

#ifndef _BFP_FIXED_INL_
#define _BFP_FIXED_INL_

#include <bfp/fixed.hpp>

namespace bfp {

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait>::make_from_literal(
    const internal::fixed_literal_provider & fixed_number_provider)
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    const std::string src = fixed_number_provider.get_str();
    const size_t point_pos = fixed_number_provider.get_point_pos();

    const fixed_type pow_factor(10);

    fixed_type result(0);
    fixed_type power(1);
    for (size_t power_v = 0u; power_v < point_pos; ++power_v)
    {
        const size_t idx = point_pos - power_v - 1u;

        if (power_v > 0u)
            power *= pow_factor;

        unsigned u_value = src[idx] - '0';
        result += fixed_type(u_value) * power;
    }

    power(1);
    for (size_t idx = point_pos + 1u; idx < src.size(); ++idx)
    {
        power /= pow_factor;

        // If bottom overflow break calculation.
        if (!power)
            break;

        unsigned u_value = src[idx] - '0';
        result += fixed_type(u_value) * power;
    }

    return result;
}

} // namespace bfp

#endif // _BFP_FIXED_INL_

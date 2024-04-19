/**************************************************************************************************
 * @file
 * @brief This file implements numeric limits for `fp`.
 * 
 * It contain class `numeric_limits` which is compatible with `std::numeric_limits`.
 * 
 * @note If you want that this numeric limits class to be in std namespace you need
 * define `BFP_STD_NUMERIC_LIMITS`.
 *************************************************************************************************/

#ifndef _BFP_NUMERIC_LIMITS_HPP_
#define _BFP_NUMERIC_LIMITS_HPP_

#include <bfp/fp.hpp>

#ifdef BFP_STD_NUMERIC_LIMITS
    #define BFP_NS std
    #define BFP_ACCESS bfp::
    #define CLASS_SPECIALIZATION < BFP_ACCESS fp<TBase, Fractional, TBaseTypeTrait> >
#else
    #define BFP_NS bfp
    #define BFP_ACCESS
    #define CLASS_SPECIALIZATION
#endif // BFP_STD_NUMERIC_LIMITS

namespace BFP_NS {

/**
 * @class
 * @brief Class with numeric limits implementations.
 * 
 * See [C++ documentation](https://en.cppreference.com/w/cpp/types/numeric_limits)
 * for more information.
 */
template <typename TBase, BFP_ACCESS LenType Fractional, typename TBaseTypeTrait>
class numeric_limits CLASS_SPECIALIZATION
{
public:

    using fp_type = BFP_ACCESS fp<TBase, Fractional, TBaseTypeTrait>;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// # Constants.
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Identifies types for which std::numeric_limits is specialized.
    static constexpr bool is_specialized = true;

    
    static constexpr bool is_signed = fp_type::base_type_trait::limits::is_signed;
    static constexpr bool is_integer = false;
    static constexpr bool is_exact = true;
    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;

    /// @brief Identifies the type that support subnormal values.
    ///
    /// The fixed point doesn't have denormalized values, because it is always
    /// set to `denorm_absent`.
    static constexpr std::float_denorm_style has_denorm = std::denorm_absent;
    static constexpr bool has_denorm_loss = false;
    static constexpr std::float_round_style round_style; // TODO: std::round_toward_zero or not?
    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;
    static constexpr int digits; // TODO: sizeof(base_type) or integer_bit_count?
    static constexpr int digits10; // TODO: Calc it.
    static constexpr int max_digits10; // TODO: Get info about it.
    static constexpr int radix = 2;
    static constexpr int min_exponent; // TODO: Does it matter for the fixed point?
    static constexpr int min_exponent10; // TODO: Does it matter for the fixed point?
    static constexpr int max_exponent; // TODO: Does it matter for the fixed point?
    static constexpr int max_exponent10; // TODO: Does it matter for the fixed point?
    static constexpr bool traps = false;
    static constexpr bool tinyness_before = false;

    static fp_type (min)()
    {
        return fp_type::create_with_raw(fp_type::base_type_trait::limits::min());
    }

    static fp_type lowest()
    {
        // TODO: Get info about it.
    }

    static fp_type (max)()
    {
        return fp_type::create_with_raw(fp_type::base_type_trait::limits::max());
    }

    static fp_type epsilon()
    {
        return fp_type::create_with_raw(fp_type::base_type(1));
    }

    static fp_type round_error()
    {
        // TODO: Get info about it.
    }

    static fp_type infinity()
    {
        return fp_type(0);
    }

    static fp_type quiet_NaN()
    {
        return fp_type(0);
    }

    static fp_type signaling_NaN()
    {
        return fp_type(0);
    }

    static fp_type denorm_min()
    {
        return fp_type(0);
    }
};

} // namespace BFP_NS

#endif // _BFP_NUMERIC_LIMITS_HPP_

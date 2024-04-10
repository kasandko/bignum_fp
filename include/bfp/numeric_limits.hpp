/**************************************************************************************************
 * @file
 * @brief This file implements numeric limits for `fp`. It contain class `numeric_limits`
 * which is compatible with `std::numeric_limits`.
 * 
 * @note If you want that this numeric limits class to be in std namespace you need
 * define `BFP_STD_NUMERIC_LIMITS`.
 *************************************************************************************************/

#ifndef _BFP_NUMERIC_LIMITS_H_
#define _BFP_NUMERIC_LIMITS_H_

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

    //! @brief Identifies types for which std::numeric_limits is specialized.
    static constexpr bool is_specialized = true;

    
    static constexpr bool is_signed = fp_type::base_type_trait::limits::is_signed;
    static constexpr bool is_integer = false;
    static constexpr bool is_exact;
    static constexpr bool has_infinity;
    static constexpr bool has_quiet_NaN;
    static constexpr bool has_signaling_NaN;

    //! @brief Identifies the type that support subnormal values.
    //!
    //! The fixed point doesn't have denormalized values, because it is always
    //! set to `denorm_absent`.
    static constexpr std::float_denorm_style has_denorm = std::denorm_absent;
    static constexpr bool has_denorm_loss;
    static constexpr std::float_round_style round_style;
    static constexpr std::float_round_style round_style;
    static constexpr bool is_iec559;
    static constexpr bool is_bounded;
    static constexpr bool is_modulo;
    static constexpr int digits;
    static constexpr int digits10;
    static constexpr int max_digits10;
    static constexpr int radix;
    static constexpr int min_exponent;
    static constexpr int min_exponent10;
    static constexpr int max_exponent;
    static constexpr int max_exponent10;
    static constexpr bool traps;
    static constexpr bool tinyness_before;

    static fp_type (min)();
    static fp_type lowest();
    static fp_type (max)();
    static fp_type epsilon();
    static fp_type round_error();
    static fp_type infinity();
    static fp_type quiet_NaN();
    static fp_type signaling_NaN();
    static fp_type denorm_min();
};

} // namespace BFP_NS

#endif // _BFP_NUMERIC_LIMITS_H_

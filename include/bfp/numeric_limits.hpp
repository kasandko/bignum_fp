/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief This file implements numeric limits for `fixed`.
 * 
 * It contain class `numeric_limits` which is compatible with `std::numeric_limits`.
 * 
 * @note If you want that this numeric limits class to be in std namespace you need
 * define `BFP_STD_NUMERIC_LIMITS`.
 *************************************************************************************************/

#ifndef _BFP_NUMERIC_LIMITS_HPP_
#define _BFP_NUMERIC_LIMITS_HPP_

#include <bfp/fixed.hpp>

#ifdef BFP_STD_NUMERIC_LIMITS
    #define BFP_NS std
    #define BFP_ACCESS bfp::
    #define CLASS_SPECIALIZATION < BFP_ACCESS fixed<TBase, Fractional, TBaseTypeTrait> >
#else
    #define BFP_NS bfp
    #define BFP_ACCESS
    #define CLASS_SPECIALIZATION
#endif // BFP_STD_NUMERIC_LIMITS

namespace bfp::internal {

constexpr float LOG10_2 = 0.30103;

constexpr int digits10(LenType bits_count)
{
    return static_cast<int>(static_cast<float>(bits_count) * LOG10_2);
}

} // bfp::internal

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

    using fixed_type = BFP_ACCESS fixed<TBase, Fractional, TBaseTypeTrait>;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// # Constants.
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Identifies types for which std::numeric_limits is specialized.
    static constexpr bool is_specialized = true;

    /// @brief 
    ///
    ///
    static constexpr bool is_signed = fixed_type::base_type_trait::limits::is_signed;

    /// @brief 
    ///
    ///
    static constexpr bool is_integer = false;

    /// @brief 
    ///
    ///
    static constexpr bool is_exact = true;

    /// @brief 
    ///
    ///
    static constexpr bool has_infinity = false;

    /// @brief 
    ///
    ///
    static constexpr bool has_quiet_NaN = false;

    /// @brief 
    ///
    ///
    static constexpr bool has_signaling_NaN = false;

    /// @brief Identifies the type that support subnormal values.
    ///
    /// The fixed point doesn't have denormalized values, because it is always
    /// set to `denorm_absent`.
    static constexpr std::float_denorm_style has_denorm = std::denorm_absent;

    /// @brief 
    ///
    ///
    static constexpr bool has_denorm_loss = false;

    /// @brief 
    ///
    ///
    static constexpr std::float_round_style round_style = std::round_toward_zero;

    /// @brief 
    ///
    ///
    static constexpr bool is_iec559 = false;

    /// @brief 
    ///
    ///
    static constexpr bool is_bounded = true;

    /// @brief 
    ///
    ///
    static constexpr bool is_modulo = false;

    /// @brief 
    ///
    ///
    static constexpr int digits = fixed_type::base_type_trait::limits::digits;

    /// @brief 
    ///
    ///
    static constexpr int digits10 = fixed_type::base_type_trait::limits::digits10;

    /// @brief 
    ///
    /// It seems numeric_limits::digits10 for
    ///    fixed_type::base_type<fixed_type::fractional_bit_count>. I.e.:
    ///    fractional_bit_count * std::log10(2);
    static constexpr int max_digits10 = bfp::internal::digits10(fixed_type::fractional_bit_count);

    /// @brief 
    ///
    ///
    static constexpr int radix = 2;

    /// @brief 
    ///
    /// 
    static constexpr int min_exponent = -fixed_type::fractional_bit_count + 1;
    
    /// @brief 
    ///
    /// 
    static constexpr int min_exponent10 = -bfp::internal::digits10(fixed_type::fractional_bit_count);

    /// @brief 
    ///
    /// @todo 
    static constexpr int max_exponent = fixed_type::integer_bit_count - 1;

    /// @brief 
    ///
    /// 
    static constexpr int max_exponent10 = bfp::internal::digits10(fixed_type::integer_bit_count);

    /// @brief 
    ///
    ///
    static constexpr bool traps = false;

    /// @brief 
    ///
    ///
    static constexpr bool tinyness_before = false;

    /// @brief 
    ///
    /// @return 
    static fixed_type (min)()
    {
        return fixed_type::create_with_raw(fixed_type::base_type_trait::limits::min());
    }

    /// @brief 
    ///
    /// @todo 
    /// @return
    static fixed_type lowest()
    {
        return fixed_type::create_with_raw(fixed_type::base_type_trait::limits::lowest());
    }

    /// @brief 
    ///
    /// @return 
    static fixed_type (max)()
    {
        return fixed_type::create_with_raw(fixed_type::base_type_trait::limits::max());
    }

    /// @brief 
    ///
    /// @return 
    static fixed_type epsilon()
    {
        return fixed_type::create_with_raw(fixed_type::base_type(1));
    }

    /// @brief 
    ///
    /// @return 
    static fixed_type round_error()
    {
        return fixed_type(0.5f);
    }

    /// @brief 
    ///
    /// @return 
    static fixed_type infinity()
    {
        return fixed_type(0);
    }

    /// @brief 
    ///
    /// @return 
    static fixed_type quiet_NaN()
    {
        return fixed_type(0);
    }

    /// @brief 
    ///
    /// @return 
    static fixed_type signaling_NaN()
    {
        return fixed_type(0);
    }

    /// @brief 
    ///
    /// @return 
    static fixed_type denorm_min()
    {
        return fixed_type(0);
    }
};

} // namespace BFP_NS

#endif // _BFP_NUMERIC_LIMITS_HPP_

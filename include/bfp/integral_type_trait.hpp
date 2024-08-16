/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief 
 *
 *************************************************************************************************/

#ifndef _BFP_INTEGRAL_TYPE_TRAIT_HPP_
#define _BFP_INTEGRAL_TYPE_TRAIT_HPP_

#include <bfp/type_defs.hpp>
#include <string>
#include <limits>
#include <type_traits>
#include <cstdint>

namespace bfp {

/// @brief 
/// @tparam TBase 
template <typename TBase>
struct integral_checker
{
    using base_type = TBase;

    /// @brief
    static constexpr bool is_valid_base_type_v =
        std::is_same_v<base_type, int8_t> ||
        std::is_same_v<base_type, int16_t> ||
        std::is_same_v<base_type, int32_t>;
};

/// @brief 
/// @tparam TBase 
/// @tparam Fractional 
template <typename TBase, LenType Fractional>
class integral_methods
{
private:

    template <typename T>
    static constexpr T power2(LenType v)
    {
        uint64_t r = 1u;
        r <<= v;
        return static_cast<T>(r);
    }

public:
    using base_type = TBase;

    inline static constexpr LenType fractional_bit_count = Fractional;
    inline static constexpr LenType integer_bit_count = sizeof (base_type) - fractional_bit_count;

    /// @brief 
    /// @param v 
    /// @return 
    static std::string to_str(const base_type & v)
    {
        const long double ldouble_v = to_long_double(v);
        return std::to_string(ldouble_v);
    }

    /// @brief 
    /// @param str 
    /// @param pos 
    /// @return 
    static base_type from_str(const std::string & str, size_t * pos = nullptr)
    {
        const long double ldouble_v = std::stold(str, pos);
        return from_long_double(ldouble_v);
    }

    /// @brief 
    /// @param v 
    /// @return 
    static std::wstring to_wstr(const base_type & v)
    {
        const long double ldouble_v = to_long_double(v);
        return std::to_wstring(ldouble_v);
    }

    /// @brief 
    /// @param str 
    /// @param pos 
    /// @return 
    static base_type from_wstr(const std::wstring & str, size_t * pos = nullptr)
    {
        const long double ldouble_v = std::stold(str, pos);
        return from_long_double(ldouble_v);
    }

    /// @brief 
    /// @param v 
    /// @return 
    static base_type from_float(float v)
    {
        const long double shifted =
            static_cast<long double>(v) * power2<long double>(fractional_bit_count);
        return static_cast<base_type>(shifted + (v >= 0.0f ? 0.5l : -0.5l));
    }

    /// @brief 
    /// @param v 
    /// @return 
    static base_type from_double(double v)
    {
        const long double shifted =
            static_cast<long double>(v) * power2<long double>(fractional_bit_count);
        return static_cast<base_type>(shifted + (v >= 0.0 ? 0.5l : -0.5l));
    }

    /// @brief 
    /// @param v 
    /// @return 
    static base_type from_long_double(long double v)
    {
        const long double shifted = v * power2<long double>(fractional_bit_count);
        return static_cast<base_type>(shifted + (v >= 0.0l ? 0.5l : -0.5l));
    }

    /// @brief 
    /// @param v 
    /// @return 
    static float to_float(const base_type & v)
    {
        const long double tmp =
            static_cast<long double>(v) / power2<long double>(fractional_bit_count);
        return static_cast<float>(tmp);
    }

    /// @brief 
    /// @param v 
    /// @return 
    static double to_double(const base_type & v)
    {
        const long double tmp =
            static_cast<long double>(v) / power2<long double>(fractional_bit_count);
        return static_cast<double>(tmp);
    }

    /// @brief 
    /// @param v 
    /// @return 
    static long double to_long_double(const base_type & v)
    {
        return static_cast<long double>(v) / power2<long double>(fractional_bit_count);
    }

    /// @brief 
    /// @param left 
    /// @param right 
    static void swap(base_type & left, base_type & right)
    {
        std::swap(left, right);
    }
};

/// @brief 
/// @tparam TBase 
/// @tparam TChecker 
template <typename TBase, typename TChecker>
class integral_type_promoter
{
private:

    inline static constexpr bool is_valid_base_type_v = TChecker::is_valid_base_type_v;

    static_assert(is_valid_base_type_v, "Promote type is not specialized for specified base type.");

    struct InvalidType { };
    template<typename T, typename U = void> struct promote_type { using type = InvalidType; };

    template<typename U> struct promote_type<int8_t, U> { using type = int16_t; };
    template<typename U> struct promote_type<int16_t, U> { using type = int32_t; };
    template<typename U> struct promote_type<int32_t, U> { using type = int64_t; };

public:

    /// @brief 
    using type = typename promote_type<TBase>::type;

    /// @brief 
    using limits = std::numeric_limits<type>;
};

/// @brief 
/// @tparam TBase 
/// @tparam Fractional 
template <typename TBase, LenType Fractional>
struct integral_type_trait
{
    using base_type = TBase;

    /// @brief 
    using checker = integral_checker<base_type>;

    /// @brief 
    using limits = std::numeric_limits<base_type>;

    /// @brief 
    using methods = integral_methods<base_type, Fractional>;

    /// @brief 
    using promotion_type = typename integral_type_promoter<base_type, checker>::type;

    /// @brief 
    using promotion_limits = typename integral_type_promoter<base_type, checker>::limits;
};

} // namespace bfp

#endif // _BFP_INTEGRAL_TYPE_TRAIT_HPP_

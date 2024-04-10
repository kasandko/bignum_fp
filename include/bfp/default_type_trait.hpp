#ifndef _BFP_BASE_TYPE_TRAIT_HPP_
#define _BFP_BASE_TYPE_TRAIT_HPP_

#include <string>
#include <bfp/type_defs.hpp>

namespace bfp {

struct invalid_type
{
    //static_assert(false, "Type is not implemented.");
};

/*
Trait similar std::numeric_limits and compatible with it.
*/
template <typename TBase>
struct default_numeric_limits
{
    
};

/*
Integral type promoter for multiplication and division.
*/
template <typename TBase>
struct default_integral_promoter
{
    using type = invalid_type;
    using limits = default_numeric_limits<type>;
};

/*
Different helper methods with base type.
*/
template <typename TBase, LenType Fractional>
struct default_helper_methods
{
    using base_type = TBase;
    static const LenType fractional_bit_count = Fractional;
    static const LenType integer_bit_count = sizeof (base_type) - fractional_bit_count;

    static std::string to_str(const base_type & v)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static base_type from_str(const std::string & str, size_t * pos = nullptr)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static std::wstring to_wstr(const base_type & v)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static base_type from_wstr(const std::wstring & str, size_t * pos = nullptr)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static base_type from_float(float v)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static base_type from_double(double v)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static base_type from_long_double(long double v)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static float to_float(const base_type & v)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static double to_double(const base_type & v)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static long double to_long_double(const base_type & v)
    {
        assert(false, "Method is not implemented.");
        return {};
    }

    static void swap(base_type & left, base_type & right)
    {
        assert(false, "Method is not implemented.");
    }
};

template <typename TBase, LenType Fractional>
struct default_type_trait
{
    using base_type = TBase;

    using limits = default_numeric_limits<base_type>;
    using methods = default_helper_methods<base_type, Fractional>;
    using promotion_type = typename default_integral_promoter<base_type>::type;
    using promotion_limits = typename default_integral_promoter<base_type>::limits;
};

} // namespace bfp

#endif // _BFP_BASE_TYPE_TRAIT_HPP_

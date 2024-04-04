#ifndef _BFP_BASE_TYPE_TRAIT_H_
#define _BFP_BASE_TYPE_TRAIT_H_

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
struct base_numeric_limits
{
    
};

/*
Integral type promoter for multiplication and division.
*/
template <typename TBase>
struct base_integral_promoter
{
    using type = invalid_type;
    using limits = base_numeric_limits<type>;
};

/*
Different helper methods with base type.
*/
template <typename TBase, LenType Fractional>
struct base_helper_methods
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
};

template <typename TBase, LenType Fractional>
struct base_type_trait
{
    using base_type = TBase;

    using limits = base_numeric_limits<base_type>;
    using methods = base_helper_methods<base_type, Fractional>;
    using promotion_type = typename base_integral_promoter<base_type>::type;
    using promotion_limits = typename base_integral_promoter<base_type>::limits;
};

} // namespace bfp

#endif // _BFP_BASE_TYPE_TRAIT_H_

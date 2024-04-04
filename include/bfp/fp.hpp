#ifndef _BFP_FP_H_
#define _BFP_FP_H_

#include <bfp/base_type_trait.hpp>

namespace bfp {



template <typename TBase, LenType Fractional, typename TBaseTypeTrait = base_type_trait<TBase, Fractional> >
class fp
{
    static_assert(std::is_same_v<TBaseTypeTrait, base_type_trait<TBase, Fractional> >, "Base type trait is not implemented.");

    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;
public:

    using base_type = TBase;

    using base_type_trait = TBaseTypeTrait;

    // The fractional part bit count.
    static constexpr LenType fractional_bit_count = Fractional;

    // The integer part bit count.
    static constexpr LenType integer_bit_count = sizeof (base_type) - fractional_bit_count;

private:

    friend class bfp::fp;

    fp(base_type value, bool)
        : _value(value)
    {
    }

    static_assert(exttr::op::is_b_lshiftable_v<base_type, base_type, LenType>, "Base type can not support <<.");
    static_assert(exttr::op::is_b_subtractive_v<base_type, base_type, int>, "Base type can not support - with int.");
    static_assert(exttr::op::is_bit_inversible_v<base_type, base_type>, "Base type can not support ~.");

    static const base_type _FRACTIONAL_MASK = (base_type(1) << fractional_bit_count) - 1;
    static const base_type _INTEGER_MASK = ~_FRACTIONAL_MASK;

    

public:

    static fp_type create_with_raw(const base_type & value)
    {
        return fp_type(value, false);
    }

    fp()
        : _value()
    {
    }

    template<typename T>
    fp(T value)
        : _value(base_type(value) << fractional_bit_count)
    {
        static_assert(std::is_convertible_v<T, base_type>, "Can not convert from T to base type.");
    }

    fp(bool value)
        : fp(static_cast<int>(value))
    {
    }

    fp(float value)
        : _value(base_type_trait::methods::from_float(value))
    {
    }

    fp(double value)
        : _value(base_type_trait::methods::from_double(value))
    {
    }

    fp(long double value)
        : _value(base_type_trait::methods::from_long_double(value))
    {
    }

    fp(const fp_type & rhs)
        : _value(rhs._value)
    {
    }

    template<LenType OtherFractional>
    fp(const fp<base_type, OtherFractional, base_type_trait> & rhs)
        : _value(rhs._value)
    {
        static_assert(exttr::op::is_a_lshiftable_v<base_type, LenType>, "Base type can not support <<=.");
        static_assert(exttr::op::is_a_rshiftable_v<base_type, LenType>, "Base type can not support >>=.");

        using other_fp_type = typename fp<base_type, OtherFractional, base_type_trait>;
        if (integer_bit_count - other_fp_type::integer_bit_count > 0)
            _value >>= integer_bit_count - other_fp_type::integer_bit_count;
        if (other_fp_type::integer_bit_count - integer_bit_count > 0)
            value_ <<= other_fp_type::integer_bit_count - integer_bit_count;
    }

private:

    base_type _value;
};

} // namespace bfp

#endif // _BFP_FP_H_

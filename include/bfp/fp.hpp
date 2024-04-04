#ifndef _BFP_FP_H_
#define _BFP_FP_H_

#include <bfp/base_type_trait.hpp>

namespace bfp {

template <typename TBase, LenType Fractional, typename TBaseTypeTrait = base_type_trait<TBase, Fractional> >
class fp
{
    static_assert(std::is_same_v<TBaseTypeTrait, base_type_trait<TBase, Fractional> >, "Base type trait is not implemented.");

    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    using _dummy = base_type_asserts<TBase>;
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
        : _value(value) // TODO: Copy constructor assert.
    {
    }

    // #assert:1.
    static const base_type _BASE_TYPE_ONE = base_type(1) << fractional_bit_count;

    // #assert:2.
    static const base_type _FRACTIONAL_MASK = _BASE_TYPE_ONE - 1;

    // #assert:3.
    static const base_type _INTEGER_MASK = ~_FRACTIONAL_MASK;

public:

    ///// Constructors /////

    static fp_type create_with_raw(const base_type & value)
    {
        return fp_type(value, false);
    }

    fp()
        : _value()
    {
    }

    // #assert:1.
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

    // #assert:6.
    fp(float value)
        : _value(base_type_trait::methods::from_float(value))
    {
    }

    // #assert:6.
    fp(double value)
        : _value(base_type_trait::methods::from_double(value))
    {
    }

    // #assert:6.
    fp(long double value)
        : _value(base_type_trait::methods::from_long_double(value))
    {
    }

    // #assert:6.
    fp(const fp_type & rhs)
        : _value(rhs._value)
    {
    }

    // #assert:4, #assert:5, #assert:6.
    template<LenType OtherFractional>
    fp(const fp<base_type, OtherFractional, base_type_trait> & rhs)
        : _value(rhs._value)
    {
        using other_fp_type = typename fp<base_type, OtherFractional, base_type_trait>;
        if (integer_bit_count - other_fp_type::integer_bit_count > 0)
            _value >>= integer_bit_count - other_fp_type::integer_bit_count;
        if (other_fp_type::integer_bit_count - integer_bit_count > 0)
            _value <<= other_fp_type::integer_bit_count - integer_bit_count;
    }
    

    ///// Operators /////

    // #assert:7.
    fp_type & operator = (const fp_type & rhs)
    {
        _value = rhs._value;
        return *this;
    }

    // #assert:6, #assert:7.
    template<LenType OtherFractional>
    fp_type & operator = (const fp<base_type, OtherFractional, base_type_trait> & rhs)
    {
        fp_type temp(rhs);
        _value = temp._value;
        return *this;
    }

    // #assert:8.
    bool operator < (const fp_type & rhs) const
    {
        return _value < rhs._value;
    }

    // #assert:9.
    bool operator == (fp_type const& rhs) const
    {
        return _value == rhs._value;
    }

    #undef BFP_COMP_OP
    #define BFP_COMP_OP(OP) bool operator##OP (fp_type const& rhs) const { return std::rel_ops::operator##OP (*this, rhs); }

    BFP_COMP_OP(!=)
    BFP_COMP_OP(<=)
    BFP_COMP_OP(>)
    BFP_COMP_OP(>=)

    #undef BFP_COMP_OP

    // #assert:10.
    bool operator ! () const
    {
        return _value == 0;
    }

    // #assert:7, #assert:11.
    fp_type operator - () const
    {
        fp_type result;

        if constexpr (std::is_signed_v<base_type>)
            result._value = -_value;
        else
            result._value = _value;

        return result;
    }

    // TODO: Point of last work.
    fp_type & operator ++ ()
    {
        _value += _BASE_TYPE_ONE;
        return *this;
    }

    fp_type & operator ++ (int)
    {
        fp_type old;
        ++(*this);
        return old;
    }

    fp_type & operator -- ()
    {
        _value -= _BASE_TYPE_ONE;
        return *this;
    }

    fp_type & operator -- (int)
    {
        fp_type old;
        --(*this);
        return old;
    }

    ///// Methods /////

    void swap(fp_type & rhs)
    {
        base_type_trait::methods::swap(_value, rhs._value);
    }

private:

    base_type _value;
};

} // namespace bfp

#endif // _BFP_FP_H_

#ifndef _BFP_FP_HPP_
#define _BFP_FP_HPP_

#include <bfp/type_defs.hpp>
#include <bfp/default_type_trait.hpp>
#include <bfp/internal/fp_number.hpp>

namespace bfp {

template <typename TBase, LenType Fractional, typename TBaseTypeTrait = default_type_trait<TBase, Fractional> >
class fp
{
    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

public:

    using base_type = TBase;

    using base_type_trait = TBaseTypeTrait;

    // The fractional part bit count.
    static constexpr LenType fractional_bit_count = Fractional;

    // The integer part bit count.
    static constexpr LenType integer_bit_count = sizeof (base_type) - fractional_bit_count;

    static const base_type BASE_TYPE_ONE = base_type(1) << fractional_bit_count;

    static const base_type FRACTIONAL_MASK = BASE_TYPE_ONE - 1;

    static const base_type INTEGER_MASK = ~FRACTIONAL_MASK;

private:

    static_assert(std::is_same_v<TBaseTypeTrait, default_type_trait<TBase, fractional_bit_count> >, "Base type trait is not implemented.");

    friend class bfp::fp;

    fp(base_type value, bool)
        : _value(value)
    {
    }

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
        using other_fp_type = typename fp<base_type, OtherFractional, base_type_trait>;
        if (integer_bit_count - other_fp_type::integer_bit_count > 0)
            _value >>= integer_bit_count - other_fp_type::integer_bit_count;
        if (other_fp_type::integer_bit_count - integer_bit_count > 0)
            _value <<= other_fp_type::integer_bit_count - integer_bit_count;
    }
    

    ///// Operators /////

    fp_type & operator = (const fp_type & rhs)
    {
        _value = rhs._value;
        return *this;
    }

    template<LenType OtherFractional>
    fp_type & operator = (const fp<base_type, OtherFractional, base_type_trait> & rhs)
    {
        fp_type temp(rhs);
        _value = temp._value;
        return *this;
    }

    fp_type & operator = (const internal::fp_number & fp_number);

    bool operator < (const fp_type & rhs) const
    {
        return _value < rhs._value;
    }

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

    bool operator ! () const
    {
        return _value == 0;
    }

    fp_type operator - () const
    {
        fp_type result;
        result._value = -_value;
        return result;
    }

    fp_type & operator ++ ()
    {
        _value += BASE_TYPE_ONE;
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
        _value -= BASE_TYPE_ONE;
        return *this;
    }

    fp_type & operator -- (int)
    {
        fp_type old;
        --(*this);
        return old;
    }

    fp_type & operator += (const fp_type & summand)
    {
        _value += summand._value;
        return *this;
    }

    fp_type operator + (const fp_type & summand)
    {
        fp_type result(*this);
        result += summand;
        return result;
    }

    fp_type & operator -= (const fp_type & diminuend)
    {
        _value -= diminuend._value;
        return *this;
    }

    fp_type operator - (const fp_type & diminuend)
    {
        fp_type result(*this);
        result -= diminuend;
        return result;
    }

    fp_type & operator *= (const fp_type & factor)
    {
        _value((base_type_trait::promotion_type(_value) * factor._value) >> fractional_bit_count);
        return *this;
    }

    fp_type operator * (const fp_type & factor)
    {
        fp_type result(*this);
        result *= factor;
        return result;
    }

    fp_type & operator /= (const fp_type & divisor)
    {
        _value((base_type_trait::promotion_type(_value) << fractional_bit_count) / divisor._value);
        return *this;
    }

    fp_type operator / (const fp_type & divisor)
    {
        fp_type result(*this);
        result /= divisor;
        return result;
    }

    fp_type & operator >>= (size_t shift)
    {
        _value >>= shift;
        return *this;
    }

    fp_type operator >> (size_t shift)
    {
        fp_type result(*this);
        result >>= shift;
        return result;
    }

    fp_type & operator <<= (size_t shift)
    {
        _value <<= shift;
        return *this;
    }

    fp_type operator << (size_t shift)
    {
        fp_type result(*this);
        result <<= shift;
        return result;
    }

    ///// Convertations /////

    #undef BFP_INTEGER_CONVERT
    #define BFP_INTEGER_CONVERT(TYPE) operator TYPE () const { return static_cast<TYPE>(_value >> fractional_bit_count); }

    BFP_INTEGER_CONVERT(char)
    BFP_INTEGER_CONVERT(wchar_t)
    BFP_INTEGER_CONVERT(int8_t)
    BFP_INTEGER_CONVERT(uint8_t)
    BFP_INTEGER_CONVERT(int16_t)
    BFP_INTEGER_CONVERT(uint16_t)
    BFP_INTEGER_CONVERT(int32_t)
    BFP_INTEGER_CONVERT(uint32_t)
    BFP_INTEGER_CONVERT(int64_t)
    BFP_INTEGER_CONVERT(uint64_t)

    #undef BFP_INTEGER_CONVERT

    operator bool () const
    {
        return static_cast<bool>(_value);
    }

    operator float () const
    {
        return base_type_trait::methods::to_float(_value);
    }

    operator double () const
    {
        return base_type_trait::methods::to_double(_value);
    }

    operator long double () const
    {
        return base_type_trait::methods::to_long_double(_value);
    }

    ///// Methods /////

    void flip_sgn()
    {
        _value = -_value;
    }

    void swap(fp_type & rhs)
    {
        base_type_trait::methods::swap(_value, rhs._value);
    }

    base_type integer() const
    {
        return _value >> fractional_bit_count;
    }

    base_type fract() const
    {
        return _value & INTEGER_MASK;
    }

    base_type & data()
    {
        return _value;
    }

    const base_type & data() const
    {
        return _value;
    }

private:

    base_type _value;
};

} // namespace bfp

#include <bfp/internal/fp.inl>

#endif // _BFP_FP_HPP_

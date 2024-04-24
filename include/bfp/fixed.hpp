/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief 
 *
 *************************************************************************************************/

#ifndef _BFP_FIXED_HPP_
#define _BFP_FIXED_HPP_

#include <bfp/type_defs.hpp>
#include <bfp/internal/literal.inl>

namespace bfp {

/// @brief 
/// @tparam TBase 
/// @tparam TBaseTypeTrait 
/// @tparam Fractional 
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
class fixed
{
    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

public:

    using base_type = TBase;

    using base_type_trait = TBaseTypeTrait;

    /// @brief The fractional part bit count.
    static constexpr LenType fractional_bit_count = Fractional;

    /// @brief The integer part bit count.
    static constexpr LenType integer_bit_count = sizeof (base_type) - fractional_bit_count;

    /// @brief 1.0 represented in a base type.
    static const base_type BASE_TYPE_ONE = base_type(1) << fractional_bit_count;

    /// @brief The mask used for get the fractional part from a base type.
    static const base_type FRACTIONAL_MASK = BASE_TYPE_ONE - 1;

    /// @brief The mask used for get the integer part from a base type.
    static const base_type INTEGER_MASK = ~FRACTIONAL_MASK;

private:

    static_assert(base_type_trait::checker::is_valid_base_type_v, "Invalid the base type for specified base type trait.");

    friend class bfp::fixed;

    /// @internal
    /// @brief 
    /// @param value 
    /// @param  
    fixed(base_type value, bool)
        : _value(value)
    {
    }

    /// @brief 
    /// @param fixed_number_provider 
    static fixed_type make_from_literal(const internal::fixed_literal_provider & fixed_number_provider);

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// # Constructors.
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief 
    /// @param value 
    /// @return 
    static fixed_type create_with_raw(const base_type & value)
    {
        return fixed_type(value, false);
    }

    /// @brief 
    fixed()
        : _value()
    {
    }

    /// @brief 
    /// @tparam T 
    /// @param value 
    template<typename T>
    fixed(T value)
        : _value(base_type(value) << fractional_bit_count)
    {
        static_assert(std::is_convertible_v<T, base_type>, "Can not convert from T to base type.");
    }

    /// @brief 
    /// @param value 
    fixed(bool value)
        : fixed(static_cast<int>(value))
    {
    }

    /// @brief 
    /// @param value 
    fixed(float value)
        : _value(base_type_trait::methods::from_float(value))
    {
    }

    /// @brief 
    /// @param value 
    fixed(double value)
        : _value(base_type_trait::methods::from_double(value))
    {
    }

    /// @brief 
    /// @param value 
    fixed(long double value)
        : _value(base_type_trait::methods::from_long_double(value))
    {
    }

    /// @brief 
    /// @param rhs 
    fixed(const fixed_type & rhs)
        : _value(rhs._value)
    {
    }

    /// @brief 
    /// @tparam OtherFractional 
    /// @param rhs 
    template<LenType OtherFractional>
    fixed(const fixed<base_type, OtherFractional, base_type_trait> & rhs)
        : _value(rhs._value)
    {
        using other_fixed_type = typename fixed<base_type, OtherFractional, base_type_trait>;
        if (integer_bit_count - other_fixed_type::integer_bit_count > 0)
            _value >>= integer_bit_count - other_fixed_type::integer_bit_count;
        if (other_fixed_type::integer_bit_count - integer_bit_count > 0)
            _value <<= other_fixed_type::integer_bit_count - integer_bit_count;
    }

    fixed(const internal::fixed_literal_provider & fixed_number_provider)
        : _value(make_from_literal(fixed_number_provider)._value)
    {
    }
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// # Operators.
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief 
    /// @param rhs 
    /// @return 
    fixed_type & operator = (const fixed_type & rhs)
    {
        _value = rhs._value;
        return *this;
    }

    /// @brief 
    /// @tparam OtherFractional 
    /// @param rhs 
    /// @return 
    template<LenType OtherFractional>
    fixed_type & operator = (const fixed<base_type, OtherFractional, base_type_trait> & rhs)
    {
        fixed_type temp(rhs);
        _value = temp._value;
        return *this;
    }

    /// @brief 
    /// @param fixed_number_provider 
    /// @return 
    fixed_type & operator = (const internal::fixed_literal_provider & fixed_number_provider)
    {
        fixed_type temp = make_from_literal(fixed_number_provider);
        _value = temp._value;
        return *this;
    }

    /// @brief 
    /// @param rhs 
    /// @return 
    bool operator < (const fixed_type & rhs) const
    {
        return _value < rhs._value;
    }

    /// @brief 
    /// @param rhs 
    /// @return 
    bool operator == (fixed_type const& rhs) const
    {
        return _value == rhs._value;
    }

    #undef BFP_COMP_OP
    #define BFP_COMP_OP(OP) bool operator##OP (fixed_type const& rhs) const { return std::rel_ops::operator##OP (*this, rhs); }

    /// @brief
    /// @return 
    BFP_COMP_OP(!=)
    BFP_COMP_OP(<=)
    BFP_COMP_OP(>)
    BFP_COMP_OP(>=)

    #undef BFP_COMP_OP

    /// @brief
    /// @return 
    bool operator ! () const
    {
        return _value == 0;
    }

    /// @brief 
    /// @return 
    fixed_type operator - () const
    {
        fixed_type result;
        result._value = -_value;
        return result;
    }

    /// @brief 
    /// @return 
    fixed_type & operator ++ ()
    {
        _value += BASE_TYPE_ONE;
        return *this;
    }

    /// @brief 
    /// @return 
    fixed_type & operator ++ (int)
    {
        fixed_type old;
        ++(*this);
        return old;
    }

    /// @brief 
    /// @return 
    fixed_type & operator -- ()
    {
        _value -= BASE_TYPE_ONE;
        return *this;
    }

    /// @brief 
    /// @return 
    fixed_type & operator -- (int)
    {
        fixed_type old;
        --(*this);
        return old;
    }

    /// @brief 
    /// @param summand 
    /// @return 
    fixed_type & operator += (const fixed_type & summand)
    {
        _value += summand._value;
        return *this;
    }

    /// @brief 
    /// @param summand 
    /// @return 
    fixed_type operator + (const fixed_type & summand)
    {
        fixed_type result(*this);
        result += summand;
        return result;
    }

    /// @brief 
    /// @param diminuend 
    /// @return 
    fixed_type & operator -= (const fixed_type & diminuend)
    {
        _value -= diminuend._value;
        return *this;
    }

    /// @brief 
    /// @param diminuend 
    /// @return 
    fixed_type operator - (const fixed_type & diminuend)
    {
        fixed_type result(*this);
        result -= diminuend;
        return result;
    }

    /// @brief 
    /// @param factor 
    /// @return 
    fixed_type & operator *= (const fixed_type & factor)
    {
        _value((base_type_trait::promotion_type(_value) * factor._value) >> fractional_bit_count);
        return *this;
    }

    /// @brief 
    /// @param factor 
    /// @return 
    fixed_type operator * (const fixed_type & factor)
    {
        fixed_type result(*this);
        result *= factor;
        return result;
    }

    /// @brief 
    /// @param divisor 
    /// @return 
    fixed_type & operator /= (const fixed_type & divisor)
    {
        _value((base_type_trait::promotion_type(_value) << fractional_bit_count) / divisor._value);
        return *this;
    }

    /// @brief 
    /// @param divisor 
    /// @return 
    fixed_type operator / (const fixed_type & divisor)
    {
        fixed_type result(*this);
        result /= divisor;
        return result;
    }

    /// @brief 
    /// @param shift 
    /// @return 
    fixed_type & operator >>= (size_t shift)
    {
        _value >>= shift;
        return *this;
    }

    /// @brief 
    /// @param shift 
    /// @return 
    fixed_type operator >> (size_t shift)
    {
        fixed_type result(*this);
        result >>= shift;
        return result;
    }

    /// @brief 
    /// @param shift 
    /// @return 
    fixed_type & operator <<= (size_t shift)
    {
        _value <<= shift;
        return *this;
    }

    /// @brief 
    /// @param shift 
    /// @return 
    fixed_type operator << (size_t shift)
    {
        fixed_type result(*this);
        result <<= shift;
        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// # Convertations.
    ///////////////////////////////////////////////////////////////////////////////////////////////

    #undef BFP_INTEGER_CONVERT
    #define BFP_INTEGER_CONVERT(TYPE) operator TYPE () const { return static_cast<TYPE>(_value >> fractional_bit_count); }

    /// @brief
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

    /// @brief
    operator bool () const
    {
        return static_cast<bool>(_value);
    }

    /// @brief 
    operator float () const
    {
        return base_type_trait::methods::to_float(_value);
    }

    /// @brief 
    operator double () const
    {
        return base_type_trait::methods::to_double(_value);
    }

    /// @brief 
    operator long double () const
    {
        return base_type_trait::methods::to_long_double(_value);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// # Methods.
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief 
    void flip_sgn()
    {
        _value = -_value;
    }

    /// @brief 
    /// @param rhs 
    void swap(fixed_type & rhs)
    {
        base_type_trait::methods::swap(_value, rhs._value);
    }

    /// @brief 
    /// @return 
    base_type integer() const
    {
        return _value >> fractional_bit_count;
    }

    /// @brief 
    /// @return 
    base_type fract() const
    {
        return _value & INTEGER_MASK;
    }

    /// @brief 
    /// @return 
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

#include <bfp/internal/fixed.inl>

#endif // _BFP_FIXED_HPP_

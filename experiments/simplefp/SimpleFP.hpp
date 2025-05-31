#ifndef SIMPLEFP_HPP
#define SIMPLEFP_HPP

#include <array>
#include <cstdint>
#include <string>

template <size_t N>
class BaseType
{
public:

    BaseType() = default;
    BaseType(const BaseType<N> & other) = default;
    BaseType(BaseType<N> && other) = default;
    explicit BaseType(const std::array<uint32_t, N> & parts);

    BaseType<N> & operator= (const BaseType<N> & other) = default;
    BaseType<N> & operator= (BaseType<N> && other) = default;

    bool operator< (const BaseType<N> & rhs) const;
    bool operator== (const BaseType<N> & rhs) const;

    bool operator!= (const BaseType<N> & rhs) const
    { return std::rel_ops::operator!= (*this, rhs); }
    bool operator<= (const BaseType<N> & rhs) const
    { return std::rel_ops::operator<= (*this, rhs); }
    bool operator> (const BaseType<N> & rhs) const
    { return std::rel_ops::operator> (*this, rhs); }
    bool operator>= (const BaseType<N> & rhs) const
    { return std::rel_ops::operator>= (*this, rhs); }

    BaseType<N> operator- () const;
    BaseType<N> & operator++ ();
    BaseType<N> & operator++ (int);
    BaseType<N> & operator-- ();
    BaseType<N> & operator-- (int);
    BaseType<N> operator~ () const;
    BaseType<N> & operator+= (const BaseType<N> & summand);
    BaseType<N> operator+ (const BaseType<N> & summand);
    BaseType<N> & operator-= (const BaseType<N> & diminuend);
    BaseType<N> operator- (const BaseType<N> & diminuend);
    BaseType<N> & operator*= (const BaseType<N> & factor);
    BaseType<N> operator* (const BaseType<N> & factor);
    BaseType<N> & operator/= (const BaseType<N> & divisor);
    BaseType<N> operator/ (const BaseType<N> & divisor);
    BaseType<N> & operator&= (const BaseType<N> & other);
    BaseType<N> operator& (const BaseType<N> & other);
    BaseType<N> & operator|= (const BaseType<N> & other);
    BaseType<N> operator| (const BaseType<N> & other);

    BaseType<N> & operator>>= (size_t shift);
    BaseType<N> operator>> (size_t shift);
    BaseType<N> & operator<<= (size_t shift);
    BaseType<N> operator<< (size_t shift);

    template <size_t NN>
    BaseType<NN> resize(bool left_pin);

private:

    std::array<uint32_t, N> _parts {};
};

///////////////////////////////////////////////////////////////////////////////////////////////////


template <size_t N>
inline BaseType<N>::BaseType(const std::array<uint32_t, N> & parts)
    : _parts(parts)
{
}

template <size_t N>
inline bool BaseType<N>::operator<(const BaseType<N> & rhs) const
{
}

template <size_t N>
inline bool BaseType<N>::operator==(const BaseType<N> & rhs) const
{
    for (size_t idx = 0u; idx < N; ++idx)
    {
        if (rhs._parts[idx] != _parts[idx])
            return false;
    }

    return true;
}

template <size_t N>
inline BaseType<N> BaseType<N>::operator-() const
{
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator++()
{
}

template <size_t N>
BaseType<N> & BaseType<N>::operator++(int)
{
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator--()
{
}

template <size_t N>
BaseType<N> & BaseType<N>::operator--(int)
{
}

template <size_t N>
inline BaseType<N> BaseType<N>::operator~() const
{
    BaseType<N> result(*this);
    for (uint32_t & part : result._parts)
        part = ~part;

    return result;
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator+=(const BaseType<N> & summand)
{

}

template <size_t N>
inline BaseType<N> BaseType<N>::operator+(const BaseType<N> & summand)
{
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator-=(const BaseType<N> & diminuend)
{
}

template <size_t N>
BaseType<N> BaseType<N>::operator-(const BaseType<N> & diminuend)
{
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator*=(const BaseType<N> & factor)
{
}

template <size_t N>
inline BaseType<N> BaseType<N>::operator*(const BaseType<N> & factor)
{
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator/=(const BaseType<N> & divisor)
{
}

template <size_t N>
inline BaseType<N> BaseType<N>::operator/(const BaseType<N> & divisor)
{
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator&=(const BaseType<N> & other)
{
    for (size_t idx = 0; idx < N; ++idx)
        _parts[idx] &= other._parts[idx];

    return *this;
}

template <size_t N>
inline BaseType<N> BaseType<N>::operator&(const BaseType<N> & other)
{
    BaseType<N> result(*this);
    for (size_t idx = 0; idx < N; ++idx)
        result._parts[idx] = _parts[idx] & other._parts[idx];

    return result;
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator|=(const BaseType<N> & other)
{
    for (size_t idx = 0; idx < N; ++idx)
        _parts[idx] |= other._parts[idx];

    return *this;
}

template <size_t N>
inline BaseType<N> BaseType<N>::operator|(const BaseType<N> & other)
{
    BaseType<N> result(*this);
    for (size_t idx = 0; idx < N; ++idx)
        result._parts[idx] = _parts[idx] | other._parts[idx];

    return result;
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator>>=(size_t shift)
{
}

template <size_t N>
inline BaseType<N> BaseType<N>::operator>>(size_t shift)
{
}

template <size_t N>
inline BaseType<N> & BaseType<N>::operator<<=(size_t shift)
{
}

template <size_t N>
inline BaseType<N> BaseType<N>::operator<<(size_t shift)
{
}

template <size_t N>
template <size_t NN>
inline BaseType<NN> BaseType<N>::resize(bool left_pin)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, size_t I, size_t F>
class SimpleFP
{
public:
    SimpleFP() = default;
    SimpleFP(const SimpleFP<N, I, F> & other);
    template <size_t NO, size_t IO, size_t FO>
    SimpleFP(const SimpleFP<NO, IO, FO> & other);
    SimpleFP(SimpleFP<N, I, F> && other);
    explicit SimpleFP(double value);
    explicit SimpleFP(const std::string & value);

    SimpleFP<N, I, F> & operator= (const SimpleFP<N, I, F> & other);
    template <size_t NO, size_t IO, size_t FO>
    SimpleFP<N, I, F> & operator= (const SimpleFP<NO, IO, FO> & other);
    SimpleFP<N, I, F> & operator= (SimpleFP<N, I, F> && other);

    bool operator< (const SimpleFP<N, I, F> & rhs) const;
    bool operator== (const SimpleFP<N, I, F> & rhs) const;

    bool operator!= (const SimpleFP<N, I, F> & rhs) const
    { return std::rel_ops::operator!= (*this, rhs); }
    bool operator<= (const SimpleFP<N, I, F> & rhs) const
    { return std::rel_ops::operator<= (*this, rhs); }
    bool operator> (const SimpleFP<N, I, F> & rhs) const
    { return std::rel_ops::operator> (*this, rhs); }
    bool operator>= (const SimpleFP<N, I, F> & rhs) const
    { return std::rel_ops::operator>= (*this, rhs); }

    bool operator! () const;
    SimpleFP<N, I, F> operator- () const;
    SimpleFP<N, I, F> & operator++ ();
    SimpleFP<N, I, F> & operator++ (int);
    SimpleFP<N, I, F> & operator-- ();
    SimpleFP<N, I, F> & operator-- (int);
    SimpleFP<N, I, F> & operator+= (const SimpleFP<N, I, F> & summand);
    SimpleFP<N, I, F> operator+ (const SimpleFP<N, I, F> & summand);
    SimpleFP<N, I, F> & operator-= (const SimpleFP<N, I, F> & diminuend);
    SimpleFP<N, I, F> operator- (const SimpleFP<N, I, F> & diminuend);
    SimpleFP<N, I, F> & operator*= (const SimpleFP<N, I, F> & factor);
    SimpleFP<N, I, F> operator* (const SimpleFP<N, I, F> & factor);
    SimpleFP<N, I, F> & operator/= (const SimpleFP<N, I, F> & divisor);
    SimpleFP<N, I, F> operator/ (const SimpleFP<N, I, F> & divisor);

protected:


private:

    BaseType<N> _value;
};

///////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F>::SimpleFP(const SimpleFP<N, I, F> & other)
{
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F>::SimpleFP(SimpleFP<N, I, F> && other)
{
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F>::SimpleFP(double value)
{
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F>::SimpleFP(const std::string & value)
{
}

template <size_t N, size_t I, size_t F>
template <size_t NO, size_t IO, size_t FO>
inline SimpleFP<N, I, F>::SimpleFP(const SimpleFP<NO, IO, FO> & other)
{
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator=(const SimpleFP<N, I, F> & other)
{
}

template <size_t N, size_t I, size_t F>
template <size_t NO, size_t IO, size_t FO>
inline SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator=(const SimpleFP<NO, IO, FO> & other)
{
}

template <size_t N, size_t I, size_t F>
SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator=(SimpleFP<N, I, F> && other)
{
}

template <size_t N, size_t I, size_t F>
inline bool SimpleFP<N, I, F>::operator<(const SimpleFP<N, I, F> & rhs) const
{
}

template <size_t N, size_t I, size_t F>
inline bool SimpleFP<N, I, F>::operator==(const SimpleFP<N, I, F> & rhs) const
{
}

template <size_t N, size_t I, size_t F>
inline bool SimpleFP<N, I, F>::operator!() const
{
//    return _value == 0;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> SimpleFP<N, I, F>::operator-() const
{
//    fixed_type result;
//    result._value = -_value;
//    return result;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator++()
{
//    _value += BASE_TYPE_ONE;
//    return *this;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator++(int)
{
//    fixed_type old;
//    ++(*this);
//    return old;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator--()
{
//    _value -= BASE_TYPE_ONE;
//    return *this;
}

template <size_t N, size_t I, size_t F>
SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator--(int)
{
//    fixed_type old;
//    --(*this);
//    return old;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator+=(const SimpleFP<N, I, F> & summand)
{
//    _value += summand._value;
//    return *this;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> SimpleFP<N, I, F>::operator+(const SimpleFP<N, I, F> & summand)
{
//    fixed_type result(*this);
//    result += summand;
//    return result;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator-=(const SimpleFP<N, I, F> & diminuend)
{
//    _value -= diminuend._value;
//    return *this;
}

template <size_t N, size_t I, size_t F>
SimpleFP<N, I, F> SimpleFP<N, I, F>::operator-(const SimpleFP<N, I, F> & diminuend)
{
//    fixed_type result(*this);
//    result -= diminuend;
//    return result;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator*=(const SimpleFP<N, I, F> & factor)
{
//    _value((base_type_trait::promotion_type(_value) * factor._value) >> fractional_bit_count);
//    return *this;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> SimpleFP<N, I, F>::operator*(const SimpleFP<N, I, F> & factor)
{
//    fixed_type result(*this);
//    result *= factor;
//    return result;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> & SimpleFP<N, I, F>::operator/=(const SimpleFP<N, I, F> & divisor)
{
//    _value((base_type_trait::promotion_type(_value) << fractional_bit_count) / divisor._value);
//    return *this;
}

template <size_t N, size_t I, size_t F>
inline SimpleFP<N, I, F> SimpleFP<N, I, F>::operator/(const SimpleFP<N, I, F> & divisor)
{
//    fixed_type result(*this);
//    result /= divisor;
//    return result;
}

#endif  // SIMPLEFP_HPP

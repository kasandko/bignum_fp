#ifndef _BFP_STRING_CVT_HPP_
#define _BFP_STRING_CVT_HPP_

#include <string>
#include <bfp/fixed.hpp>

namespace bfp {

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> stof(const std::string & str, size_t * pos = nullptr)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fixed<TBase, Fractional, TBaseTypeTrait> stof(const std::wstring & str, size_t * pos = nullptr)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
std::string ftos(const fixed<TBase, Fractional, TBaseTypeTrait> & v)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
std::wstring ftows(const fixed<TBase, Fractional, TBaseTypeTrait> & v)
{
    // TODO: Implementation.
}

} // namespace bfp

#endif // _BFP_STRING_CVT_HPP_

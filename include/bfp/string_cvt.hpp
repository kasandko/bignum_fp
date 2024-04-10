#ifndef _BFP_STRING_CVT_HPP_
#define _BFP_STRING_CVT_HPP_

#include <string>
#include <bfp/fp.hpp>

namespace bfp {

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> stofp(const std::string & str, size_t * pos = nullptr)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
fp<TBase, Fractional, TBaseTypeTrait> stofp(const std::wstring & str, size_t * pos = nullptr)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
std::string fptos(const fp<TBase, Fractional, TBaseTypeTrait> & v)
{
    // TODO: Implementation.
}

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
std::wstring fptows(const fp<TBase, Fractional, TBaseTypeTrait> & v)
{
    // TODO: Implementation.
}

} // namespace bfp

#endif // _BFP_STRING_CVT_HPP_

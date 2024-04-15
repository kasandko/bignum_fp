#ifndef _BFP_FP_NUMBER_HPP_
#define _BFP_FP_NUMBER_HPP_

#include <bfp/type_defs.hpp>

#ifndef BFP_MATHEMATICAL_CONSTANTS_PRECISION
#define BFP_MATHEMATICAL_CONSTANTS_PRECISION 50
#endif

namespace bfp::internal {

class fp_number
{
    friend fp_number operator "" _fp_number(const char* str, size_t size);

public:

    template <typename TBase, LenType Fractional>
    TBase make_base() const
    {
        // TODO:
    }

private:

    fp_number() = delete;

    fp_number(const char* str, size_t size)
        : str(str)
        , size(size)
    {
    }

private:
    const char* str;
    size_t size;
};

fp_number operator "" _fp_number(const char* str, size_t size)
{

};

} // namespace bfp::internal

#endif // _BFP_FP_NUMBER_HPP_

#ifndef _BFP_NUMBERS_H_
#define _BFP_NUMBERS_H_

#include <bfp/fp.hpp>

namespace bfp {

template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
class  numbers
{
public:

    using fp_type = fp<TBase, Fractional, TBaseTypeTrait>;

    inline static const fp_type e;
    inline static const fp_type log2e;
    inline static const fp_type log10e;
    inline static const fp_type pi;
    inline static const fp_type inv_pi;
    inline static const fp_type inv_sqrtpi;
    inline static const fp_type ln2;
    inline static const fp_type ln10;
    inline static const fp_type sqrt2;
    inline static const fp_type sqrt3;
    inline static const fp_type inv_sqrt3;
    inline static const fp_type egamma;
    inline static const fp_type phi;

};

} // namespace bfp

#endif // _BFP_NUMBERS_H_

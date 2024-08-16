/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief This file implements `std::numbers` analog for `fp`.
 * 
 * It contain class `numbers` which is compatible with `std::numbers`, but it can not be located
 * in `std` namespace. You can change the precision if you define
 * `BFP_MATHEMATICAL_CONSTANTS_PRECISION` with neend the precision: number of decimal digits after
 * point. Default precision is 50.
 *************************************************************************************************/

#ifndef _BFP_NUMBERS_HPP_
#define _BFP_NUMBERS_HPP_

#include <bfp/fixed.hpp>
#include <bfp/literal.hpp>

namespace bfp {

/**
 * @class
 * @brief Class with numbers implementations.
 * 
 * See C++ documentation for more information:
 * - [Mathematical constants](https://en.cppreference.com/w/cpp/numeric/constants)
 * - [Standard library header <numbers>](https://en.cppreference.com/w/cpp/header/numbers)
 */
template <typename TBase, LenType Fractional, typename TBaseTypeTrait>
class  numbers
{
public:

    using fixed_type = fixed<TBase, Fractional, TBaseTypeTrait>;

    using internal;
    
    /// @brief Mathematical constant e.
    ///
    /// https://oeis.org/A001113
    inline static const fixed_type e           = 2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178_fixed;
    
    /// @brief Binary logarithm of e.
    ///
    /// https://oeis.org/A007525
    inline static const fixed_type log2e       = 1.442695040888963407359924681001892137426645954152985934135449406931109219181185079885526622_fixed;
    
    /// @brief Common logarithm of e.
    ///
    /// https://oeis.org/A002285
    inline static const fixed_type log10e      = 0.434294481903251827651128918916605082294397005803666566114453783165864649208870774729224949_fixed;
    
    /// @brief Mathematical constant pi.
    ///
    /// https://oeis.org/A000720
    inline static const fixed_type pi          = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825_fixed;
    
    /// @brief 1/pi.
    ///
    /// https://oeis.org/A049541
    inline static const fixed_type inv_pi      = 0.318309886183790671537767526745028724068919291480912897495334688117793595268453070180227605_fixed;
    
    /// @brief 1/sqrt(pi).
    ///
    /// https://oeis.org/A087197
    inline static const fixed_type inv_sqrtpi  = 0.564189583547756286948079451560772585844050629328998856844085721710642468441493414486743660_fixed;
    
    /// @brief Natural logarithm of 2.
    ///
    /// https://oeis.org/A002162
    inline static const fixed_type ln2         = 0.693147180559945309417232121458176568075500134360255254120680009493393621969694715605863326_fixed;
    
    /// @brief Natural logarithm of 10.
    ///
    /// https://oeis.org/A002392
    inline static const fixed_type ln10        = 2.302585092994045684017991454684364207601101488628772976033327900967572609677352480235997205_fixed;
    
    /// @brief Square root of 2.
    ///
    /// https://oeis.org/A002193
    inline static const fixed_type sqrt2       = 1.414213562373095048801688724209698078569671875376948073176679737990732478462107038850387534_fixed;
    
    /// @brief Square root of 3.
    ///
    /// https://oeis.org/A002194
    inline static const fixed_type sqrt3       = 1.732050807568877293527446341505872366942805253810380628055806979451933016908800037081146186_fixed;
    
    /// @brief 1/sqrt(3).
    ///
    /// https://oeis.org/A020760
    inline static const fixed_type inv_sqrt3   = 0.577350269189625764509148780501957455647601751270126876018602326483977672302933345693715395_fixed;
    
    /// @brief Euler's constant (or the Euler-Mascheroni constant), gamma.
    ///
    /// https://oeis.org/A001620
    inline static const fixed_type egamma      = 0.577215664901532860606512090082402431042159335939923598805767234884867726777664670936947063_fixed;
    
    /// @brief Golden ratio phi (or tau).
    ///
    /// https://oeis.org/A001622
    inline static const fixed_type phi         = 1.618033988749894848204586834365638117720309179805762862135448622705260462818902449707207204_fixed;

};

} // namespace bfp

#endif // _BFP_NUMBERS_HPP_

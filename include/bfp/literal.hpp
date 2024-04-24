/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief 
 *
 *************************************************************************************************/

#ifndef _BFP_LITERAL_HPP_
#define _BFP_LITERAL_HPP_

#include <bfp/internal/literal.inl>

#ifdef BFP_GLOBAL_SPACE_LITERAL
    #define BFP_NS
#else
    #define BFP_NS bfp
#endif

namespace BFP_NS {

/// @brief 
/// @return 
bfp::internal::fixed_literal_provider operator "" _fixed(const char* str, size_t size)
{
    const size_t point_pos = bfp::internal::fixed_literal_provider::find_point_pos(str, size);
    return {{str, point_pos + bfp::internal::fixed_literal_provider::dec_precision}, point_pos};
}

} // namespace BFP_NS

#endif // _BFP_LITERAL_HPP_

/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief This file contains base types, macros and other for `fixed` type and other parts of
 * bignum_fp.
 *
 *************************************************************************************************/

#ifndef _BFP_TYPE_DEFS_HPP_
#define _BFP_TYPE_DEFS_HPP_

#include <cstdint>

namespace bfp {

/// @brief The type represeting base type size, fractional part size and integer part size.
using LenType = int16_t;

/// @brief The preprocessor macro for mark libraries methods and functions which are not
/// implemented yet.
#undef _BFP_NOT_IMPLEMENTED_ASSERT
#define _BFP_NOT_IMPLEMENTED_ASSERT                 \
    assert("Not implemented.");                     \
    return {};

} // namespace bfp

#endif // _BFP_TYPE_DEFS_HPP_

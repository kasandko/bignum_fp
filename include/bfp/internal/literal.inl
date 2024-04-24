/**************************************************************************************************
 * @file
 * @author Konovalov Aleksander
 * @copyright This file is part of library bignum_fp and has the same license. @see LICENSE.txt
 * @brief 
 *
 *************************************************************************************************/

#ifndef _BFP_LITERAL_INL_
#define _BFP_LITERAL_INL_

#include <string>

#ifndef BFP_MATHEMATICAL_CONSTANTS_PRECISION
#define BFP_MATHEMATICAL_CONSTANTS_PRECISION 50u
#endif

namespace bfp::internal {

class fixed_literal_provider
{
public:

    inline static const size_t dec_precision = BFP_MATHEMATICAL_CONSTANTS_PRECISION;

    fixed_literal_provider() = delete;

    fixed_literal_provider(const std::string & str, size_t point_pos)
        : _point_pos(point_pos)
        , _str(str)
    {
    }

    static constexpr size_t find_point_pos(const char* str, size_t size)
    {
        for (size_t idx = 0u; idx < size; ++idx)
        {
            if (str[idx] == '.')
                return idx;
        }

        return size;
    }

    std::string get_str() const { return _str; }
    size_t get_point_pos() const { return _point_pos; }

private:
    std::string _str;
    size_t _point_pos;
};

} // namespace bfp::internal

#endif // _BFP_LITERAL_INL_

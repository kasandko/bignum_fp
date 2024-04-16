#ifndef _BFP_FP_NUMBER_HPP_
#define _BFP_FP_NUMBER_HPP_

#include <string>

#ifndef BFP_MATHEMATICAL_CONSTANTS_PRECISION
#define BFP_MATHEMATICAL_CONSTANTS_PRECISION 50u
#endif

namespace bfp::internal {

class fp_number
{
    friend fp_number operator "" _fp_number(const char* str, size_t size);

public:

    inline static const size_t dec_precision = BFP_MATHEMATICAL_CONSTANTS_PRECISION;

    std::string _get_str() const { return _str; }

private:

    fp_number() = delete;

    fp_number(const std::string & str, size_t point_pos)
        : _str(str)
        , _point_pos(point_pos)
    {
    }

private:
    std::string _str;
    size_t _point_pos;
};

constexpr size_t _find_point_pos(const char* str, size_t size)
{
    for (size_t idx = 0u; idx < size; ++idx)
    {
        if (str[idx] == '.')
            return idx;
    }

    return size;
}

fp_number operator "" _fp_number(const char* str, size_t size)
{
    const size_t point_pos = _find_point_pos(str, size);
    return {{str, point_pos + BFP_MATHEMATICAL_CONSTANTS_PRECISION}, point_pos};
};

} // namespace bfp::internal

#endif // _BFP_FP_NUMBER_HPP_

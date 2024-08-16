#include "bfp/fixed.hpp"
#include "bfp/limits.hpp"
#include "bfp/literal.hpp"
#include "bfp/math.hpp"
#include "bfp/numbers.hpp"
#include "bfp/numeric_limits.hpp"
#include "bfp/stream.hpp"
#include "bfp/string_cvt.hpp"
#include "bfp/integral_type_trait.hpp"

#include <cstdint>

int main()
{
    bfp::fixed<int32_t, 16, bfp::integral_type_trait<int32_t, 16>> fixed_point;
    return 0;
}

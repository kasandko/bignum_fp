#pragma once

#include "bfp/fixed.hpp"
#include "bfp/integral_type_trait.hpp"

#include <cstdint>

using fixed32 = bfp::fixed<int32_t, 16, bfp::integral_type_trait<int32_t, 16>>;

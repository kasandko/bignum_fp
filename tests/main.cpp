
#include "tupp.hpp"
#include "tests/integral/base_tests.hpp"
#include "tests/integral/casts_tests.hpp"
#include "tests/integral/operators_tests.hpp"
#include "tests/integral/other_tests.hpp"

int main(int argc, char* argv[])
{
    // base tests.
    TUPP_ADD_TEST(integral::test_construction);
    TUPP_ADD_TEST(integral::test_copy_assignment);
    TUPP_ADD_TEST(integral::test_copy_construction);

    // casts tests.
    TUPP_ADD_TEST(integral::test_to_char);
    TUPP_ADD_TEST(integral::test_to_signed_char);
    TUPP_ADD_TEST(integral::test_to_unsigned_char);
    TUPP_ADD_TEST(integral::test_to_short);
    TUPP_ADD_TEST(integral::test_to_unsigned_short);
    TUPP_ADD_TEST(integral::test_to_int);
    TUPP_ADD_TEST(integral::test_to_unsigned_int);
    TUPP_ADD_TEST(integral::test_to_long);
    TUPP_ADD_TEST(integral::test_to_unsigned_long);
    TUPP_ADD_TEST(integral::test_to_long_long);
    TUPP_ADD_TEST(integral::test_to_unsigned_long_long);
    TUPP_ADD_TEST(integral::test_to_bool);
    TUPP_ADD_TEST(integral::test_to_float);
    TUPP_ADD_TEST(integral::test_to_double);
    TUPP_ADD_TEST(integral::test_to_long_double);
    TUPP_ADD_TEST(integral::test_to_base);

    // other tests.
    TUPP_ADD_TEST(integral::test_ostream);
    TUPP_ADD_TEST(integral::test_istream);
    TUPP_ADD_TEST(integral::test_create_with_raw);
    TUPP_ADD_TEST(integral::test_fract);

    // operators tests.
    TUPP_ADD_TEST(integral::test_comparison);
    TUPP_ADD_TEST(integral::test_equality);
    TUPP_ADD_TEST(integral::test_unary_minus);
    TUPP_ADD_TEST(integral::test_prefix_increment);
    TUPP_ADD_TEST(integral::test_prefix_decrement);
    TUPP_ADD_TEST(integral::test_postfix_increment);
    TUPP_ADD_TEST(integral::test_postfix_decrement);
    TUPP_ADD_TEST(integral::test_add);
    TUPP_ADD_TEST(integral::test_subtract);
    TUPP_ADD_TEST(integral::test_add_assign);
    TUPP_ADD_TEST(integral::test_subtract_assign);
    TUPP_ADD_TEST(integral::test_multiply);
    TUPP_ADD_TEST(integral::test_divide);
    TUPP_ADD_TEST(integral::test_multiply_assign);
    TUPP_ADD_TEST(integral::test_divide_assign);
    TUPP_ADD_TEST(integral::test_lshift);
    TUPP_ADD_TEST(integral::test_rshift);

    return tupp::run(argc, argv);
}

#include "operators_tests.hpp"

#include "tests/f_types.hpp"
#include "tinyunitpp/tupp.hpp"

namespace integral {

void test_comparison()
{
    fixed32 fp01(0);
    fixed32 fp02(0);

    fixed32 fp11(-10);
    fixed32 fp12(10);
    fixed32 fp13(200);
    fixed32 fp14(10);
    fixed32 fp15(-200);
    fixed32 fp16(-10);

    fixed32 fp21(-34.15);
    fixed32 fp22(34.15);
    fixed32 fp23(115.67);
    fixed32 fp24(34.15);
    fixed32 fp25(-115.67);
    fixed32 fp26(-34.15);

    // With 0.
    TUPP_ASSERT_TRUE(fp01 >= fp02);
    TUPP_ASSERT_TRUE(fp01 <= fp02);
    TUPP_ASSERT_TRUE(fp01 > fp11);
    TUPP_ASSERT_TRUE(fp01 >= fp11);
    TUPP_ASSERT_TRUE(fp01 < fp12);
    TUPP_ASSERT_TRUE(fp01 <= fp12);
    TUPP_ASSERT_TRUE(fp01 > fp21);
    TUPP_ASSERT_TRUE(fp01 >= fp21);
    TUPP_ASSERT_TRUE(fp01 < fp22);
    TUPP_ASSERT_TRUE(fp01 <= fp22);

    TUPP_ASSERT_FALSE(fp01 <= fp02);
    TUPP_ASSERT_FALSE(fp01 >= fp02);
    TUPP_ASSERT_FALSE(fp01 < fp11);
    TUPP_ASSERT_FALSE(fp01 <= fp11);
    TUPP_ASSERT_FALSE(fp01 > fp12);
    TUPP_ASSERT_FALSE(fp01 >= fp12);
    TUPP_ASSERT_FALSE(fp01 < fp21);
    TUPP_ASSERT_FALSE(fp01 <= fp21);
    TUPP_ASSERT_FALSE(fp01 > fp22);
    TUPP_ASSERT_FALSE(fp01 >= fp22);

    // Two integral pos numbers.
    TUPP_ASSERT_TRUE(fp12 >= fp14);
    TUPP_ASSERT_TRUE(fp12 <= fp14);
    TUPP_ASSERT_TRUE(fp12 > fp13);
    TUPP_ASSERT_TRUE(fp12 >= fp13);
    TUPP_ASSERT_TRUE(fp13 < fp12);
    TUPP_ASSERT_TRUE(fp13 <= fp12);

    TUPP_ASSERT_FALSE(fp12 <= fp14);
    TUPP_ASSERT_FALSE(fp12 >= fp14);
    TUPP_ASSERT_FALSE(fp12 < fp13);
    TUPP_ASSERT_FALSE(fp12 <= fp13);
    TUPP_ASSERT_FALSE(fp13 > fp12);
    TUPP_ASSERT_FALSE(fp13 >= fp12);

    // Two integral neg numbers.
    TUPP_ASSERT_TRUE(fp11 <= fp16);
    TUPP_ASSERT_TRUE(fp11 >= fp16);
    TUPP_ASSERT_TRUE(fp11 > fp15);
    TUPP_ASSERT_TRUE(fp11 >= fp15);
    TUPP_ASSERT_TRUE(fp15 < fp11);
    TUPP_ASSERT_TRUE(fp15 <= fp11);

    TUPP_ASSERT_FALSE(fp11 >= fp16);
    TUPP_ASSERT_FALSE(fp11 <= fp16);
    TUPP_ASSERT_FALSE(fp11 < fp15);
    TUPP_ASSERT_FALSE(fp11 <= fp15);
    TUPP_ASSERT_FALSE(fp15 > fp11);
    TUPP_ASSERT_FALSE(fp15 >= fp11);

    // Integral neg and pos.
    TUPP_ASSERT_TRUE(fp12 > fp11);
    TUPP_ASSERT_TRUE(fp12 >= fp11);
    TUPP_ASSERT_TRUE(fp11 < fp12);
    TUPP_ASSERT_TRUE(fp11 <= fp12);

    TUPP_ASSERT_FALSE(fp12 < fp11);
    TUPP_ASSERT_FALSE(fp12 <= fp11);
    TUPP_ASSERT_FALSE(fp11 > fp12);
    TUPP_ASSERT_FALSE(fp11 >= fp12);

    // Two float pos numbers.
    TUPP_ASSERT_TRUE(fp22 >= fp24);
    TUPP_ASSERT_TRUE(fp22 <= fp24);
    TUPP_ASSERT_TRUE(fp22 > fp23);
    TUPP_ASSERT_TRUE(fp22 >= fp23);
    TUPP_ASSERT_TRUE(fp23 < fp22);
    TUPP_ASSERT_TRUE(fp23 <= fp22);

    TUPP_ASSERT_FALSE(fp22 <= fp24);
    TUPP_ASSERT_FALSE(fp22 >= fp24);
    TUPP_ASSERT_FALSE(fp22 < fp23);
    TUPP_ASSERT_FALSE(fp22 <= fp23);
    TUPP_ASSERT_FALSE(fp23 > fp22);
    TUPP_ASSERT_FALSE(fp23 >= fp22);

    // Two float neg numbers.
    TUPP_ASSERT_TRUE(fp21 <= fp26);
    TUPP_ASSERT_TRUE(fp21 >= fp26);
    TUPP_ASSERT_TRUE(fp21 > fp25);
    TUPP_ASSERT_TRUE(fp21 >= fp25);
    TUPP_ASSERT_TRUE(fp25 < fp21);
    TUPP_ASSERT_TRUE(fp25 <= fp21);

    TUPP_ASSERT_FALSE(fp21 >= fp26);
    TUPP_ASSERT_FALSE(fp21 <= fp26);
    TUPP_ASSERT_FALSE(fp21 < fp25);
    TUPP_ASSERT_FALSE(fp21 <= fp25);
    TUPP_ASSERT_FALSE(fp25 > fp21);
    TUPP_ASSERT_FALSE(fp25 >= fp21);

    // Float pos and neg numbers.
    TUPP_ASSERT_TRUE(fp22 > fp21);
    TUPP_ASSERT_TRUE(fp22 >= fp21);
    TUPP_ASSERT_TRUE(fp21 < fp22);
    TUPP_ASSERT_TRUE(fp21 <= fp22);

    TUPP_ASSERT_FALSE(fp22 < fp21);
    TUPP_ASSERT_FALSE(fp22 <= fp21);
    TUPP_ASSERT_FALSE(fp21 > fp22);
    TUPP_ASSERT_FALSE(fp21 >= fp22);

    fixed32 a_fp0(0);
    fixed32 a_fp1((signed char)-128);
    fixed32 a_fp2((unsigned char)127);
    fixed32 a_fp3((signed short)-32768);
    fixed32 a_fp4((unsigned short)32767);
    fixed32 a_fp5((signed int)-32768);
    fixed32 a_fp6((unsigned int)32767);
    fixed32 a_fp7((float)-1.5);
    fixed32 a_fp8((float)1.5);
    fixed32 a_fp9((double)-1.5);
    fixed32 a_fp10((double)1.5);
    fixed32 a_fp11((long double)-1.5);
    fixed32 a_fp12((long double)1.5);

    TUPP_ASSERT_TRUE(a_fp1 < a_fp2);
    TUPP_ASSERT_TRUE(a_fp2 > a_fp1);
    TUPP_ASSERT_FALSE(a_fp4 < a_fp3);
    TUPP_ASSERT_FALSE(a_fp3 > a_fp4);
}

void test_equality()
{
    fixed32 fp01(0);
    fixed32 fp02(0);

    fixed32 fp11(-10);
    fixed32 fp12(10);
    fixed32 fp13(200);
    fixed32 fp14(10);
    fixed32 fp15(-200);
    fixed32 fp16(-10);

    fixed32 fp21(-34.15);
    fixed32 fp22(34.15);
    fixed32 fp23(115.67);
    fixed32 fp24(34.15);
    fixed32 fp25(-115.67);
    fixed32 fp26(-34.15);

    // With 0.
    TUPP_ASSERT_TRUE(fp01 == fp02);
    TUPP_ASSERT_TRUE(fp01 != fp11);
    TUPP_ASSERT_TRUE(fp01 != fp12);
    TUPP_ASSERT_TRUE(fp01 != fp21);
    TUPP_ASSERT_TRUE(fp01 != fp22);

    TUPP_ASSERT_FALSE(fp01 != fp02);
    TUPP_ASSERT_FALSE(fp01 == fp11);
    TUPP_ASSERT_FALSE(fp01 == fp12);
    TUPP_ASSERT_FALSE(fp01 == fp21);
    TUPP_ASSERT_FALSE(fp01 == fp22);

    // Two integral pos numbers.
    TUPP_ASSERT_TRUE(fp12 == fp14);

    // Two integral neg numbers.
    TUPP_ASSERT_TRUE(fp11 == fp16);

    // Two float pos numbers.
    TUPP_ASSERT_TRUE(fp22 == fp24);

    // Two float neg numbers.
    TUPP_ASSERT_TRUE(fp21 == fp26);
}

void test_unary_minus()
{
    fixed32 fp1((signed char)-127);
    fixed32 fp2((unsigned char)127);
    fixed32 fp3((signed short)-32767);
    fixed32 fp4((unsigned short)32767);
    fixed32 fp5((signed int)-32767);
    fixed32 fp6((unsigned int)32767);
    fixed32 fp7((float)-1.5);
    fixed32 fp8((float)1.5);
    fixed32 fp9((double)-1.5);
    fixed32 fp10((double)1.5);
    fixed32 fp11((long double)-1.5);
    fixed32 fp12((long double)1.5);

    TUPP_ASSERT(fp1, -fp2);
    TUPP_ASSERT(-fp1, fp2);
    TUPP_ASSERT(fp3, -fp4);
    TUPP_ASSERT(-fp3, fp4);
    TUPP_ASSERT(fp5, -fp6);
    TUPP_ASSERT(-fp5, fp6);
    TUPP_ASSERT(fp7, -fp8);
    TUPP_ASSERT(-fp7, fp8);
    TUPP_ASSERT(fp9, -fp10);
    TUPP_ASSERT(-fp9, fp10);
    TUPP_ASSERT(fp11, -fp12);
    TUPP_ASSERT(-fp11, fp12);
}

void test_prefix_increment()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_prefix_decrement()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_postfix_increment()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_postfix_decrement()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_add()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_subtract()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_add_assign()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_subtract_assign()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_multiply()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_divide()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_multiply_assign()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_divide_assign()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_lshift()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

void test_rshift()
{
    TUPP_MESSAGE("TODO: Not implemented.");
}

} // namespace integral

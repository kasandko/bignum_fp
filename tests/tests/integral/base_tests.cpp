#include "base_tests.hpp"
#include "tests/f_types.hpp"
#include "tinyunitpp/tupp.hpp"

namespace integral
{

void test_construction()
{
    fixed32 fp0(0);
    TUPP_ASSERT((int)fp0, 0);

    fixed32 fp1((signed char)-128);
    TUPP_ASSERT((signed char)fp1, -128);

    fixed32 fp2((unsigned char)127);
    TUPP_ASSERT((unsigned char)fp2, 127);

    fixed32 fp3((signed short)-32768);
    TUPP_ASSERT((signed short)fp3, -32768);

    fixed32 fp4((unsigned short)32767);
    TUPP_ASSERT((unsigned short)fp4, 32767);

    fixed32 fp5((signed int)-32768);
    TUPP_ASSERT((signed int)fp5, -32768);

    fixed32 fp6((unsigned int)32767);
    TUPP_ASSERT((unsigned int)fp6, 32767);

    fixed32 fp7((float)-1.5);
    TUPP_ASSERT((float)fp7, -1.5);

    fixed32 fp8((float)1.5);
    TUPP_ASSERT((float)fp8, 1.5);

    fixed32 fp9((double)-1.5);
    TUPP_ASSERT((double)fp9, -1.5);

    fixed32 fp10((double)1.5);
    TUPP_ASSERT((double)fp10, 1.5);

    fixed32 fp11((long double)-1.5);
    TUPP_ASSERT((long double)fp11, -1.5);

    fixed32 fp12((long double)1.5);
    TUPP_ASSERT((long double)fp12, 1.5);
}

void test_copy_construction()
{
    fixed32 fp0(0);
    fixed32 fp0c(fp0);
    TUPP_ASSERT((int)fp0c, 0);

    fixed32 fp1((signed char)-128);
    fixed32 fp1c(fp1);
    TUPP_ASSERT((signed char)fp1c, -128);

    fixed32 fp2((unsigned char)127);
    fixed32 fp2c(fp2);
    TUPP_ASSERT((unsigned char)fp2c, 127);

    fixed32 fp3((signed short)-32768);
    fixed32 fp3c(fp3);
    TUPP_ASSERT((signed short)fp3c, -32768);

    fixed32 fp4((unsigned short)32767);
    fixed32 fp4c(fp4);
    TUPP_ASSERT((unsigned short)fp4c, 32767);

    fixed32 fp5((signed int)-32768);
    fixed32 fp5c(fp5);
    TUPP_ASSERT((signed int)fp5c, -32768);

    fixed32 fp6((unsigned int)32767);
    fixed32 fp6c(fp6);
    TUPP_ASSERT((unsigned int)fp6c, 32767);

    fixed32 fp7((float)-1.5);
    fixed32 fp7c(fp7);
    TUPP_ASSERT((float)fp7c, -1.5);

    fixed32 fp8((float)1.5);
    fixed32 fp8c(fp8);
    TUPP_ASSERT((float)fp8c, 1.5);

    fixed32 fp9((double)-1.5);
    fixed32 fp9c(fp9);
    TUPP_ASSERT((double)fp9c, -1.5);

    fixed32 fp10((double)1.5);
    fixed32 fp10c(fp10);
    TUPP_ASSERT((double)fp10c, 1.5);

    fixed32 fp11((long double)-1.5);
    fixed32 fp11c(fp11);
    TUPP_ASSERT((long double)fp11c, -1.5);

    fixed32 fp12((long double)1.5);
    fixed32 fp12c(fp12);
    TUPP_ASSERT((long double)fp12c, 1.5);
}

void test_copy_assignment()
{
    fixed32 fp0(0);
    fixed32 fp0c;
    fp0c = fp0;
    TUPP_ASSERT((int)fp0c, 0);

    fixed32 fp1((signed char)-128);
    fixed32 fp1c;
    fp1c = fp1;
    TUPP_ASSERT((signed char)fp1c, -128);

    fixed32 fp2((unsigned char)127);
    fixed32 fp2c;
    fp2c = fp2;
    TUPP_ASSERT((unsigned char)fp2c, 127);

    fixed32 fp3((signed short)-32768);
    fixed32 fp3c;
    fp3c = fp3;
    TUPP_ASSERT((signed short)fp3c, -32768);

    fixed32 fp4((unsigned short)32767);
    fixed32 fp4c;
    fp4c = fp4;
    TUPP_ASSERT((unsigned short)fp4c, 32767);

    fixed32 fp5((signed int)-32768);
    fixed32 fp5c;
    fp5c = fp5;
    TUPP_ASSERT((signed int)fp5c, -32768);

    fixed32 fp6((unsigned int)32767);
    fixed32 fp6c;
    fp6c = fp6;
    TUPP_ASSERT((unsigned int)fp6c, 32767);

    fixed32 fp7((float)-1.5);
    fixed32 fp7c;
    fp7c = fp7;
    TUPP_ASSERT((float)fp7c, -1.5);

    fixed32 fp8((float)1.5);
    fixed32 fp8c;
    fp8c = fp8;
    TUPP_ASSERT((float)fp8c, 1.5);

    fixed32 fp9((double)-1.5);
    fixed32 fp9c;
    fp9c = fp9;
    TUPP_ASSERT((double)fp9c, -1.5);

    fixed32 fp10((double)1.5);
    fixed32 fp10c;
    fp10c = fp10;
    TUPP_ASSERT((double)fp10c, 1.5);

    fixed32 fp11((long double)-1.5);
    fixed32 fp11c;
    fp11c = fp11;
    TUPP_ASSERT((long double)fp11c, -1.5);

    fixed32 fp12((long double)1.5);
    fixed32 fp12c;
    fp12c = fp12;
    TUPP_ASSERT((long double)fp12c, 1.5);
}

} // namespace integral

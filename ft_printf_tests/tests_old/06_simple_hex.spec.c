#include "project.h"

UT_TEST(06_simple_hex)
{
	UT_PRINTF_ASSERT("Max int %x\n", 2147483647);
	UT_PRINTF_ASSERT("%x\n", 647);
	UT_PRINTF_ASSERT("%x\n", 0xff);
}

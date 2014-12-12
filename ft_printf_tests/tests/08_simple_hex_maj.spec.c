#include "project.h"

UT_TEST(08_simple_hex_maj)
{
	UT_PRINTF_ASSERT("Max int %X\n", 2147483647);
	UT_PRINTF_ASSERT("%X\n", 647);
	UT_PRINTF_ASSERT("%X\n", 0xff);
}

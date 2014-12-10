#include "project.h"

UT_TEST(02_simple_decimal)
{
	UT_PRINTF_ASSERT("Positive %d\n", 42);
	UT_PRINTF_ASSERT("Negative %d\n", -42);
	UT_PRINTF_ASSERT("Min int %d\n", -2147483648);
	UT_PRINTF_ASSERT("Positive %i\n", 42);
	UT_PRINTF_ASSERT("Negative %i\n", -42);
	UT_PRINTF_ASSERT("Min int %i\n", -2147483648);
}

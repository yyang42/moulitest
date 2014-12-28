#include "project.h"

UT_TEST(10_long_decimal)
{
	UT_PRINTF_ASSERT("Positive %D\n", 42);
	UT_PRINTF_ASSERT("Negative %D\n", -42);
	UT_PRINTF_ASSERT("Min int %D\n", -9223372036854775807);
}

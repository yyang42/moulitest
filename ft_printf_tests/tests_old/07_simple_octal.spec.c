#include "project.h"

UT_TEST(07_simple_octal)
{
	UT_PRINTF_ASSERT("Max int %o\n", 2147483647);
	UT_PRINTF_ASSERT("%o\n", 647);
}

#include "project.h"

UT_TEST(34_precision)
{
	UT_PRINTF_ASSERT("%.5d\n", -42);
	UT_PRINTF_ASSERT("%.5u\n", 42);
	UT_PRINTF_ASSERT("%.5i\n", -42);
	UT_PRINTF_ASSERT("%.5U\n", 42);
	UT_PRINTF_ASSERT("%.5x\n", 0xff);
	UT_PRINTF_ASSERT("%.5X\n", 0xff);
	UT_PRINTF_ASSERT("%.5o\n", 0732);
	UT_PRINTF_ASSERT("%.5O\n", 042);
	UT_PRINTF_ASSERT("%.20s\n", "This is a string");
	UT_PRINTF_ASSERT("%.5c\n", 'c');
}

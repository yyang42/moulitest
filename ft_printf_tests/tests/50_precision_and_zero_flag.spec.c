#include "project.h"

UT_TEST(50_precision_and_zero_flag)
{
	UT_PRINTF_ASSERT("%10.5d\n", -42);
	UT_PRINTF_ASSERT("%10.5u\n", 42);
	UT_PRINTF_ASSERT("%10.5i\n", -42);
	UT_PRINTF_ASSERT("%10.5U\n", 42);
	UT_PRINTF_ASSERT("%10.5x\n", 0xff);
	UT_PRINTF_ASSERT("%10.5X\n", 0xff);
	UT_PRINTF_ASSERT("%10.5o\n", 0732);
	UT_PRINTF_ASSERT("%10.5O\n", 042);
	UT_PRINTF_ASSERT("%10.20s\n", "This is a string");
	UT_PRINTF_ASSERT("%10.5c\n", 'c');
	UT_PRINTF_ASSERT("%30.25p\n", &strlen);
}

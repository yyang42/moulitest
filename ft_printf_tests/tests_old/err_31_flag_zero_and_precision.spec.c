#include "project.h"

UT_TEST(err_31_flag_zero_and_precision)
{
	UT_PRINTF_ASSERT("%010.5d\n", -42);
	UT_PRINTF_ASSERT("%010.5u\n", 42);
	UT_PRINTF_ASSERT("%010.5i\n", -42);
	UT_PRINTF_ASSERT("%010.5U\n", 42);
	UT_PRINTF_ASSERT("%010.5x\n", 0xff);
	UT_PRINTF_ASSERT("%010.5X\n", 0xff);
	UT_PRINTF_ASSERT("%010.5o\n", 0732);
	UT_PRINTF_ASSERT("%010.5O\n", 042);
	UT_PRINTF_ASSERT("%025.20s\n", "This is a string");
	UT_PRINTF_ASSERT("%010.5c\n", 'c');
}

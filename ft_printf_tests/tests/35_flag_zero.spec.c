#include "project.h"

UT_TEST(35_flag_zero)
{
	UT_PRINTF_ASSERT("%05d\n", -42);
	UT_PRINTF_ASSERT("%05u\n", 42);
	UT_PRINTF_ASSERT("%05i\n", -42);
	UT_PRINTF_ASSERT("%05U\n", 42);
	UT_PRINTF_ASSERT("%05x\n", 0xff);
	UT_PRINTF_ASSERT("%05X\n", 0xff);
	UT_PRINTF_ASSERT("%05o\n", 0732);
	UT_PRINTF_ASSERT("%05O\n", 042);
	UT_PRINTF_ASSERT("%020s\n", "This is a string");
	UT_PRINTF_ASSERT("%05c\n", 'c');
	UT_PRINTF_ASSERT("%025p\n", &strlen);
}

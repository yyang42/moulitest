#include "project.h"

UT_TEST(err_30_zero_and_minus_flags)
{
	UT_PRINTF_ASSERT("%-05d\n", -42);
	UT_PRINTF_ASSERT("%-05u\n", 42);
	UT_PRINTF_ASSERT("%-05i\n", -42);
	UT_PRINTF_ASSERT("%-05U\n", 42);
	UT_PRINTF_ASSERT("%-05x\n", 0xff);
	UT_PRINTF_ASSERT("%-05X\n", 0xff);
	UT_PRINTF_ASSERT("%-05o\n", 0732);
	UT_PRINTF_ASSERT("%-05O\n", 042);
	UT_PRINTF_ASSERT("%-020s\n", "This is a string");
	UT_PRINTF_ASSERT("%-05c\n", 'c');
	UT_PRINTF_ASSERT("%0-5d\n", -42);
	UT_PRINTF_ASSERT("%0-5u\n", 42);
	UT_PRINTF_ASSERT("%0-5i\n", -42);
	UT_PRINTF_ASSERT("%0-5U\n", 42);
	UT_PRINTF_ASSERT("%0-5x\n", 0xff);
	UT_PRINTF_ASSERT("%0-5X\n", 0xff);
	UT_PRINTF_ASSERT("%0-5o\n", 0732);
	UT_PRINTF_ASSERT("%0-5O\n", 042);
	UT_PRINTF_ASSERT("%0-20s\n", "This is a string");
	UT_PRINTF_ASSERT("%0-5c\n", 'c');
}

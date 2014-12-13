#include "project.h"

UT_TEST(51_field_width_and_space_flag)
{
	UT_PRINTF_ASSERT("% 10d\n", -42);
	UT_PRINTF_ASSERT("% 10u\n", 42);
	UT_PRINTF_ASSERT("% 10i\n", -42);
	UT_PRINTF_ASSERT("% 10U\n", 42);
	UT_PRINTF_ASSERT("% 10x\n", 0xff);
	UT_PRINTF_ASSERT("% 10X\n", 0xff);
	UT_PRINTF_ASSERT("% 10o\n", 0732);
	UT_PRINTF_ASSERT("% 10O\n", 042);
	UT_PRINTF_ASSERT("% 100s\n", "This is a string");
	UT_PRINTF_ASSERT("% 10c\n", 'c');
	UT_PRINTF_ASSERT("% 25p\n", &strlen);
}

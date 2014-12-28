#include "project.h"

UT_TEST(32_flag_diese)
{
	UT_PRINTF_ASSERT("%#d\n", 42);
	UT_PRINTF_ASSERT("%#x\n", 0xff);
	UT_PRINTF_ASSERT("%#X\n", 0xff);
	UT_PRINTF_ASSERT("%#o\n", 0732);
	UT_PRINTF_ASSERT("%#O\n", 042);
}

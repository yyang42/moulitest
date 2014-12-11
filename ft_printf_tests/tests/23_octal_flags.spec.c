#include "project.h"

UT_TEST(23_octal_flags)
{
	UT_PRINTF_ASSERT("%lo\n", LONG_MAX);
	UT_PRINTF_ASSERT("%llo\n", LLONG_MAX);
	UT_PRINTF_ASSERT("%ho\n", SHRT_MAX);
	UT_PRINTF_ASSERT("%ho\n", 's');
	UT_PRINTF_ASSERT("%hho\n", 'A');
	UT_PRINTF_ASSERT("%hho\n", '|');
	UT_PRINTF_ASSERT("%jo\n", LLONG_MAX);
	UT_PRINTF_ASSERT("%zo\n", LONG_MAX);
	UT_PRINTF_ASSERT("%lo\n", LONG_MAX);
	UT_PRINTF_ASSERT("%llo\n", LLONG_MAX);
	UT_PRINTF_ASSERT("%ho\n", SHRT_MAX);
	UT_PRINTF_ASSERT("%hho\n", '@');
	UT_PRINTF_ASSERT("%hho\n", 127);
	UT_PRINTF_ASSERT("%jo\n", LLONG_MAX);
	UT_PRINTF_ASSERT("%zo\n", LONG_MAX);
}

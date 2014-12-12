#include "project.h"

UT_TEST(24_hex_maj_flags)
{
	UT_PRINTF_ASSERT("%lX\n", LONG_MAX);
	UT_PRINTF_ASSERT("%llX\n", LLONG_MAX);
	UT_PRINTF_ASSERT("%hX\n", SHRT_MAX);
	UT_PRINTF_ASSERT("%hX\n", 's');
	UT_PRINTF_ASSERT("%hhX\n", 'A');
	UT_PRINTF_ASSERT("%hhX\n", '|');
	UT_PRINTF_ASSERT("%jX\n", LLONG_MAX);
	UT_PRINTF_ASSERT("%zX\n", LONG_MAX);
	UT_PRINTF_ASSERT("%hhX\n", '@');
	UT_PRINTF_ASSERT("%hhX\n", 127);
}

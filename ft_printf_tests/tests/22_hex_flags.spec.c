#include "project.h"

UT_TEST(22_hex_flags)
{
	UT_PRINTF_ASSERT("%lx\n", LONG_MAX);
	UT_PRINTF_ASSERT("%llx\n", LLONG_MAX);
	UT_PRINTF_ASSERT("%hx\n", SHRT_MAX);
	UT_PRINTF_ASSERT("%hx\n", 's');
	UT_PRINTF_ASSERT("%hhx\n", 'A');
	UT_PRINTF_ASSERT("%hhx\n", '|');
	UT_PRINTF_ASSERT("%jx\n", LLONG_MAX);
	UT_PRINTF_ASSERT("%zx\n", LONG_MAX);
	UT_PRINTF_ASSERT("%hhx\n", '@');
	UT_PRINTF_ASSERT("%hhx\n", 127);
}

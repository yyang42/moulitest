#include "project.h"

UT_TEST(40_wide_char)
{
	UT_PRINTF_ASSERT("%lc\n", L'A');
	UT_PRINTF_ASSERT("%C\n", L'A');
	UT_PRINTF_ASSERT("%lc\n", 945);
	UT_PRINTF_ASSERT("%C\n", 945);
	UT_PRINTF_ASSERT("%lc\n", 0x801);
	UT_PRINTF_ASSERT("%C\n", 0x801);
	UT_PRINTF_ASSERT("%lc\n", 0x10903);
	UT_PRINTF_ASSERT("%C\n", 0x10903);
}

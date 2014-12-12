#include "project.h"

UT_TEST(21_unsigned_flags)
{
	UT_PRINTF_ASSERT("%lu\n", ULONG_MAX);
	UT_PRINTF_ASSERT("%hu\n", USHRT_MAX);
	UT_PRINTF_ASSERT("%hhu\n", 255);
	UT_PRINTF_ASSERT("%zu\n", ULONG_MAX);
}

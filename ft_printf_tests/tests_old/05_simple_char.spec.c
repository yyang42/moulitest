#include "project.h"

UT_TEST(05_simple_char)
{
	UT_PRINTF_ASSERT("%c\n", '1');
	UT_PRINTF_ASSERT("%c\n", 'C');
	UT_PRINTF_ASSERT("%c\n", 'i');
	UT_PRINTF_ASSERT("%c\n", '#');
}

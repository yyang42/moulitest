#include "project.h"

UT_TEST(52_field_width_and_precision)
{
	wchar_t wstr[5];

	wstr[0] = L'A';
	wstr[1] = 945;
	wstr[2] = 0x801;
	wstr[3] = 0x10903;
	wstr[4] = L'\0';
	UT_PRINTF_ASSERT("%10.5d\n", -42);
	UT_PRINTF_ASSERT("%10.5u\n", 42);
	UT_PRINTF_ASSERT("%10.5i\n", -42);
	UT_PRINTF_ASSERT("%10.5U\n", 42);
	UT_PRINTF_ASSERT("%10.5x\n", 0xff);
	UT_PRINTF_ASSERT("%10.5X\n", 0xff);
	UT_PRINTF_ASSERT("%10.5o\n", 0732);
	UT_PRINTF_ASSERT("%10.5O\n", 042);
	UT_PRINTF_ASSERT("%30.5s\n", "This is a string");
	UT_PRINTF_ASSERT("%30.5ls\n", wstr);
	UT_PRINTF_ASSERT("%10.5c\n", 'c');
	UT_PRINTF_ASSERT("%25.5p\n", &strlen);
}

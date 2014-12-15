#include "project.h"

UT_TEST(33_minimum_field_width)
{
	wchar_t wstr[5];

	wstr[0] = L'A';
	wstr[1] = 945;
	wstr[2] = 0x801;
	wstr[3] = 0x10903;
	wstr[4] = L'\0';
	UT_PRINTF_ASSERT("%5d\n", -42);
	UT_PRINTF_ASSERT("%5u\n", 42);
	UT_PRINTF_ASSERT("%5i\n", -42);
	UT_PRINTF_ASSERT("%5U\n", 42);
	UT_PRINTF_ASSERT("%5x\n", 0xff);
	UT_PRINTF_ASSERT("%5X\n", 0xff);
	UT_PRINTF_ASSERT("%5o\n", 0732);
	UT_PRINTF_ASSERT("%5O\n", 042);
	UT_PRINTF_ASSERT("%20s\n", "This is a string");
	UT_PRINTF_ASSERT("%20S\n", wstr);
	UT_PRINTF_ASSERT("%5c\n", 'c');
	UT_PRINTF_ASSERT("%25p\n", &strlen);
}

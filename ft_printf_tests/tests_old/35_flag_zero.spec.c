#include "project.h"

UT_TEST(35_flag_zero)
{
	wchar_t wstr[5];

	wstr[0] = L'A';
	wstr[1] = 945;
	wstr[2] = 0x801;
	wstr[3] = 0x10903;
	wstr[4] = L'\0';
	UT_PRINTF_ASSERT("%05d\n", -42);
	UT_PRINTF_ASSERT("%05u\n", 42);
	UT_PRINTF_ASSERT("%05i\n", -42);
	UT_PRINTF_ASSERT("%05U\n", 42);
	UT_PRINTF_ASSERT("%05x\n", 0xff);
	UT_PRINTF_ASSERT("%05X\n", 0xff);
	UT_PRINTF_ASSERT("%05o\n", 0732);
	UT_PRINTF_ASSERT("%05O\n", 042);
	UT_PRINTF_ASSERT("%020s\n", "This is a string");
	UT_PRINTF_ASSERT("%020ls\n", wstr);
	UT_PRINTF_ASSERT("%05c\n", 'c');
	UT_PRINTF_ASSERT("%025p\n", &strlen);
}

#include "project.h"

UT_TEST(51_field_width_and_space_flag)
{
	wchar_t wstr[5];

	wstr[0] = L'A';
	wstr[1] = 945;
	wstr[2] = 0x801;
	wstr[3] = 0x10903;
	wstr[4] = L'\0';
	UT_PRINTF_ASSERT("% 10d\n", -42);
	UT_PRINTF_ASSERT("% 10u\n", 42);
	UT_PRINTF_ASSERT("% 10i\n", -42);
	UT_PRINTF_ASSERT("% 10U\n", 42);
	UT_PRINTF_ASSERT("% 10x\n", 0xff);
	UT_PRINTF_ASSERT("% 10X\n", 0xff);
	UT_PRINTF_ASSERT("% 10o\n", 0732);
	UT_PRINTF_ASSERT("% 10O\n", 042);
	UT_PRINTF_ASSERT("% 100s\n", "This is a string");
	UT_PRINTF_ASSERT("% 100ls\n", wstr);
	UT_PRINTF_ASSERT("% 10c\n", 'c');
	UT_PRINTF_ASSERT("% 25p\n", &strlen);
}

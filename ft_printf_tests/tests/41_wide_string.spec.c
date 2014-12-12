#include "project.h"
#include <wchar.h>

UT_TEST(41_wide_string)
{
	wchar_t	str[5];

	str[0] = L'A';
	str[1] = 945;
	str[2] = 0x801;
	str[3] = 0x10903;
	str[4] = '\0';
	UT_PRINTF_ASSERT("%ls\n", str);
	UT_PRINTF_ASSERT("%S\n", str);
}

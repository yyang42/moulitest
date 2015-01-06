#include "project.h"

UT_TEST(ft_strtrim)
{
	UT_ASSERT_EQ(strcmp(ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t"), "AAA \t BBB"), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrim("\t\t\n\t\t   "), ""), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrim(""), ""), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrim("abc"), "abc"), 0);

	/*ft_strtrim(NULL);*/
}

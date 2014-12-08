#include "project.h"

UT_TEST(ft_strequ)
{
	UT_ASSERT_EQ(ft_strequ("", ""), 1);
	UT_ASSERT_EQ(ft_strequ("abcDEF", "abcDEF"), 1);
	UT_ASSERT_EQ(ft_strequ("abcDEF", "abcDEf"), 0);
}

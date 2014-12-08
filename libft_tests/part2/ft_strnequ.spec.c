#include "project.h"

UT_TEST(ft_strnequ)
{
	UT_ASSERT_EQ(ft_strnequ("ededeqdf", "", 0), 1);
	UT_ASSERT_EQ(ft_strnequ("abcde", "abdfe", 2), 1);
	UT_ASSERT_EQ(ft_strnequ("abc", "abc", 100), 1);
	UT_ASSERT_EQ(ft_strnequ("abcde", "abdde", 5), 0);
}

#include "project.h"

UT_TEST(ft_strncmp)
{
	UT_ASSERT(ft_strncmp("\200", "\0", 1) > 0);
	UT_ASSERT_EQ(ft_strncmp("abc", "abcde", 3), 0);
	UT_ASSERT_EQ(ft_strncmp("abc", "abc\0defg", 100), 0);
	UT_ASSERT_NEQ(ft_strncmp("ab\0cde", "abcc\0e", 20), 0);
	UT_ASSERT_EQ(ft_strncmp("q", "a", 0), strncmp("q", "a", 0));
}

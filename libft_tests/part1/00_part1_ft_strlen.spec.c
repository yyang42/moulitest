#include "project.h"

UT_TEST(ft_strlen)
{
	UT_ASSERT_EQ(ft_strlen("chat"), strlen("chat"));
	UT_ASSERT_EQ(ft_strlen(""), strlen(""));
	UT_ASSERT_EQ(ft_strlen("aaa\0aaa"), strlen("aaa\0aaa"));
}

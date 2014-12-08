#include "project.h"

UT_TEST(ft_abs)
{
	UT_ASSERT_EQ(ft_abs(12), abs(12));
	UT_ASSERT_EQ(ft_abs(-12), abs(-12));
	UT_ASSERT_EQ(ft_abs(28), abs(28));
	UT_ASSERT_EQ(ft_abs(0), abs(0));
}

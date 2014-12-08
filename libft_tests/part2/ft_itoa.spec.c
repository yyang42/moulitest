#include "project.h"

UT_TEST(ft_itoa)
{
	UT_ASSERT_EQ(strcmp(ft_itoa(0), "0"), 0);
	UT_ASSERT_EQ(strcmp(ft_itoa(-1234), "-1234"), 0);
	UT_ASSERT_EQ(strcmp(ft_itoa(123456000), "123456000"), 0);
	UT_ASSERT_EQ(strcmp(ft_itoa(-2147483648), "-2147483648"), 0);
}

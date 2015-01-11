#include "project.h"

UT_TEST(ft_toupper)
{
	UT_ASSERT_EQ(ft_toupper('a'), 'A');
	UT_ASSERT_EQ(ft_toupper(12345), 12345);
	UT_ASSERT_EQ(ft_toupper(' '), ' ');
	UT_ASSERT_EQ(ft_toupper('Z'), 'Z');
}

#include "project.h"

UT_TEST(ft_isalnum)
{
	UT_ASSERT_EQ(ft_isalnum('a'), isalnum('a'));
	UT_ASSERT_EQ(ft_isalnum('a' + 0x100), isalnum('a' + 0x100));
	UT_ASSERT_EQ(ft_isalnum('2'), isalnum('2'));
	UT_ASSERT_EQ(ft_isalnum('Z'), isalnum('Z'));
	UT_ASSERT_EQ(ft_isalnum('t'), isalnum('t'));
	UT_ASSERT_EQ(ft_isalnum(0), isalnum(0));
	UT_ASSERT_EQ(ft_isalnum(1), isalnum(1));
	UT_ASSERT_EQ(ft_isalnum(9999), isalnum(9999));
	UT_ASSERT_EQ(ft_isalnum('1'), isalnum('1'));
	UT_ASSERT_EQ(ft_isalnum('2'), isalnum('2'));
	UT_ASSERT_EQ(ft_isalnum('A'), isalnum('A'));
	UT_ASSERT_EQ(ft_isalnum('Z'), isalnum('Z'));
	UT_ASSERT_EQ(ft_isalnum(' '), isalnum(' '));
	UT_ASSERT_EQ(ft_isalnum('%'), isalnum('%'));
	UT_ASSERT_EQ(ft_isalnum('\t'), isalnum('\t'));
	UT_ASSERT_EQ(ft_isalnum('\n'), isalnum('\n'));
	UT_ASSERT_EQ(ft_isalnum('\v'), isalnum('\v'));
	UT_ASSERT_EQ(ft_isalnum('\b'), isalnum('\b'));
	UT_ASSERT_EQ(ft_isalnum(7), isalnum(7));
}

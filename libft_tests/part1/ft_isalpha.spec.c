#include "project.h"

UT_TEST(ft_isalpha)
{
	UT_ASSERT_EQ(ft_isalpha('a'), isalpha('a'));
	UT_ASSERT_EQ(ft_isalpha('a' + 0x100), isalpha('a' + 0x100));
	UT_ASSERT_EQ(ft_isalpha('2'), isalpha('2'));
	UT_ASSERT_EQ(ft_isalpha('Z'), isalpha('Z'));
	UT_ASSERT_EQ(ft_isalpha('t'), isalpha('t'));
	UT_ASSERT_EQ(ft_isalpha(0), isalpha(0));
	UT_ASSERT_EQ(ft_isalpha(1), isalpha(1));
	UT_ASSERT_EQ(ft_isalpha(9999), isalpha(9999));
	UT_ASSERT_EQ(ft_isalpha('1'), isalpha('1'));
	UT_ASSERT_EQ(ft_isalpha('2'), isalpha('2'));
	UT_ASSERT_EQ(ft_isalpha('A'), isalpha('A'));
	UT_ASSERT_EQ(ft_isalpha('Z'), isalpha('Z'));
	UT_ASSERT_EQ(ft_isalpha(' '), isalpha(' '));
	UT_ASSERT_EQ(ft_isalpha('%'), isalpha('%'));
	UT_ASSERT_EQ(ft_isalpha('\t'), isalpha('\t'));
	UT_ASSERT_EQ(ft_isalpha('\n'), isalpha('\n'));
	UT_ASSERT_EQ(ft_isalpha('\v'), isalpha('\v'));
	UT_ASSERT_EQ(ft_isalpha('\b'), isalpha('\b'));
	UT_ASSERT_EQ(ft_isalpha(7), isalpha(7));
}

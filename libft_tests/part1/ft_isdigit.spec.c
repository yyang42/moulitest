#include "project.h"

UT_TEST(ft_isdigit)
{
	UT_ASSERT_EQ(ft_isdigit('a'), isdigit('a'));
	UT_ASSERT_EQ(ft_isdigit('a' + 0x100), isdigit('a' + 0x100));
	UT_ASSERT_EQ(ft_isdigit('2'), isdigit('2'));
	UT_ASSERT_EQ(ft_isdigit('Z'), isdigit('Z'));
	UT_ASSERT_EQ(ft_isdigit('t'), isdigit('t'));
	UT_ASSERT_EQ(ft_isdigit(0), isdigit(0));
	UT_ASSERT_EQ(ft_isdigit(1), isdigit(1));
	UT_ASSERT_EQ(ft_isdigit(9999), isdigit(9999));
	UT_ASSERT_EQ(ft_isdigit('1'), isdigit('1'));
	UT_ASSERT_EQ(ft_isdigit('2'), isdigit('2'));
	UT_ASSERT_EQ(ft_isdigit('A'), isdigit('A'));
	UT_ASSERT_EQ(ft_isdigit('Z'), isdigit('Z'));
	UT_ASSERT_EQ(ft_isdigit(' '), isdigit(' '));
	UT_ASSERT_EQ(ft_isdigit('%'), isdigit('%'));
	UT_ASSERT_EQ(ft_isdigit('\t'), isdigit('\t'));
	UT_ASSERT_EQ(ft_isdigit('\n'), isdigit('\n'));
	UT_ASSERT_EQ(ft_isdigit('\v'), isdigit('\v'));
	UT_ASSERT_EQ(ft_isdigit('\b'), isdigit('\b'));
	UT_ASSERT_EQ(ft_isdigit(7), isdigit(7));
}

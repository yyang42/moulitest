#include "project.h"

UT_TEST(ft_isascii)
{
	UT_ASSERT_EQ(ft_isascii('a'), isascii('a'));
	UT_ASSERT_EQ(ft_isascii('a' + 0x100), isascii('a' + 0x100));
	UT_ASSERT_EQ(ft_isascii('2'), isascii('2'));
	UT_ASSERT_EQ(ft_isascii('Z'), isascii('Z'));
	UT_ASSERT_EQ(ft_isascii('t'), isascii('t'));
	UT_ASSERT_EQ(ft_isascii(0), isascii(0));
	UT_ASSERT_EQ(ft_isascii(1), isascii(1));
	UT_ASSERT_EQ(ft_isascii(9999), isascii(9999));
	UT_ASSERT_EQ(ft_isascii('1'), isascii('1'));
	UT_ASSERT_EQ(ft_isascii('2'), isascii('2'));
	UT_ASSERT_EQ(ft_isascii('A'), isascii('A'));
	UT_ASSERT_EQ(ft_isascii('Z'), isascii('Z'));
	UT_ASSERT_EQ(ft_isascii(' '), isascii(' '));
	UT_ASSERT_EQ(ft_isascii('%'), isascii('%'));
	UT_ASSERT_EQ(ft_isascii('\t'), isascii('\t'));
	UT_ASSERT_EQ(ft_isascii('\n'), isascii('\n'));
	UT_ASSERT_EQ(ft_isascii('\v'), isascii('\v'));
	UT_ASSERT_EQ(ft_isascii('\b'), isascii('\b'));
	UT_ASSERT_EQ(ft_isascii(7), isascii(7));
}

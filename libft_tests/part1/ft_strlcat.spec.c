#include "project.h"

UT_TEST(ft_strlcat)
{
	char	buf[10];
	bzero(buf, 10);
	strcpy(buf, "abc");
	ft_strlcat(buf, "abcdefghijklmnop", 10);
	UT_ASSERT_EQ(strcmp(buf, "abcabcdef"), 0);
	UT_ASSERT_EQ(ft_strlcat(buf, "abcd", 2), 6);
	bzero(buf, 10);
	UT_ASSERT_EQ(ft_strlcat(buf, "abc", 10), 3);
	UT_ASSERT_EQ(ft_strlcat(buf, "def", 10), 6);
	bzero(buf, 10);
	memset(buf, 'a', 10);
	UT_ASSERT_EQ(ft_strlcat(buf, "ccc", 10), 13);

	UT_ASSERT_EQ(ft_strlcat(strdup("abc\0\0\0"), "ccc", 0), strlcat(strdup("abc\0\0\0"), "ccc", 0));
	UT_ASSERT_EQ(ft_strlcat(strdup("abc\0\0\0"), "ccc", 1), strlcat(strdup("abc\0\0\0"), "ccc", 1));
	UT_ASSERT_EQ(ft_strlcat(strdup("abc\0\0\0"), "ccc", 6), strlcat(strdup("abc\0\0\0"), "ccc", 6));
	UT_ASSERT_EQ(ft_strlcat(strdup("abc\0\0\0"), "ccc", 10), strlcat(strdup("abc\0\0\0"), "ccc", 10));
}

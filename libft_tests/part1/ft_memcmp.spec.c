#include "project.h"

UT_TEST(ft_memcmp)
{
	char	*t = "ab\0ab";

	UT_ASSERT_EQ(ft_memcmp(t, t, 5), 0);
	UT_ASSERT_NEQ(ft_memcmp(t, "abcab", 5) ,0);
	UT_ASSERT(ft_memcmp("aaa", "aab", 4) < 0);
	UT_ASSERT_EQ(ft_memcmp("aab", "aac", 2), 0);
	UT_ASSERT_EQ(ft_memcmp("aww", "bpp", 0), 0);
	UT_ASSERT(ft_memcmp("\200", "\0", 1) > 0);
}

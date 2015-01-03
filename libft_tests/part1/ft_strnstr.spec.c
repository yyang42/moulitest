#include "project.h"

UT_TEST(ft_strnstr)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
	UT_ASSERT_EQ(strnstr(buf, "9", 3), ft_strnstr(buf, "9", 3));
	UT_ASSERT_EQ(ft_strnstr(buf, "", 6), buf);
	UT_ASSERT_EQ(ft_strnstr(buf, "deux", 5), strnstr(buf, "deux", 5));
	UT_ASSERT_EQ(ft_strnstr(buf, "9", 10), strnstr(buf, "9", 10));
	UT_ASSERT_EQ(ft_strnstr(buf, "9", 8), strnstr(buf, "9", 8));
	buf[9] = '6';
	UT_ASSERT_EQ(strnstr(buf, "cinq", 10), ft_strnstr(buf, "cinq", 10));
	UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
	UT_ASSERT_EQ(strnstr(buf, "9682", 10), ft_strnstr(buf, "9682", 10));
	UT_ASSERT_EQ(strnstr(buf, "6", 10), ft_strnstr(buf, "6", 10));
	buf[1] = 0;
	UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));

	char	buf2[] = "ozarabozaraboze";
	UT_ASSERT_EQ(strnstr(buf2, "ozaraboze", 15), ft_strnstr(buf2, "ozaraboze", 15));
}

#include "project.h"

UT_TEST(ft_strcpy)
{
	char	buf1[6], buf2[6];

	bzero(buf1, 6);
	bzero(buf2, 6);

	UT_ASSERT_EQ(strcmp(ft_strcpy(buf1, "abcde"), strcpy(buf1, "abcde")), 0);
	UT_ASSERT_EQ(strcmp(ft_strcpy(buf1, "abc"), strcpy(buf1, "abc")), 0);
}

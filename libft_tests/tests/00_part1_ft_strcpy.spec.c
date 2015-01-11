#include <project.h>

static void unittest1(t_test *test)
{

	char	buf1[6], buf2[6];

	bzero(buf1, 6);
	bzero(buf2, 6);

	mt_assert(strcmp(ft_strcpy(buf1, "abcde"), strcpy(buf1, "abcde")) == 0);
}

static void unittest2(t_test *test)
{

	char	buf1[6], buf2[6];

	bzero(buf1, 6);
	bzero(buf2, 6);

	mt_assert(strcmp(ft_strcpy(buf1, "abc"), strcpy(buf1, "abc")) == 0);
}

void	suite_00_part1_ft_strcpy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
}

#include <project.h>

static void test1(t_test *test)
{
	mt_assert(strcmp(ft_strjoin("abc", "def"), "abcdef") == 0);
}

static void test2(t_test *test)
{
	mt_assert(strcmp(ft_strjoin("", ""), "") == 0);
}

void	suite_01_part2_ft_strjoin(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
}

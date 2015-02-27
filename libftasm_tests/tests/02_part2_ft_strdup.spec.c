#include <project.h>

static void unittest1(t_test *test)
{
	mt_assert(strcmp(ft_strdup("aaaaa"), "aaaaa") == 0);
}

static void unittest2(t_test *test)
{
	mt_assert(strcmp(ft_strdup(""), "") == 0);
}

static void unittest3(t_test *test)
{
	char *s1;
	char *s2;

	s1 = "aaa";
	s2 = ft_strdup(s1);
	mt_assert(s1 != s2);
}

void	suite_02_part2_ft_strdup(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
}

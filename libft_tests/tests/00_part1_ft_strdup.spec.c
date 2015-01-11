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
	char	*c;

	c = "AbC";
	mt_assert(c != ft_strdup(c));
}

void	suite_00_part1_ft_strdup(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
}

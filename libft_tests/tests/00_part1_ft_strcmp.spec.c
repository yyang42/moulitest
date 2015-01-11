#include <project.h>

static void unittest1(t_test *test)
{
	mt_assert(ft_strcmp("", "") == 0);
}

static void unittest2(t_test *test)
{
	mt_assert(ft_strcmp("abc", "abc") == 0);
}

static void unittest3(t_test *test)
{
	mt_assert(ft_strcmp("abc", "abd") < 0);
}

static void unittest4(t_test *test)
{
	mt_assert(ft_strcmp("\200", "\0") > 0);
}

static void unittest5(t_test *test)
{
	mt_assert(ft_strcmp("a", "abcde") != 0);
}

void	suite_00_part1_ft_strcmp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
	SUITE_ADD_TEST(suite, unittest4);
	SUITE_ADD_TEST(suite, unittest5);
}

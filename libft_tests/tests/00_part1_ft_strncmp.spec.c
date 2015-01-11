#include <project.h>

static void unittest1(t_test *test)
{
	mt_assert(ft_strncmp("\200", "\0", 1) > 0);
}

static void unittest2(t_test *test)
{
	mt_assert(ft_strncmp("abc", "abcde", 3) == 0);
}

static void unittest3(t_test *test)
{
	mt_assert(ft_strncmp("abc", "abc\0defg", 100) == 0);
}

static void unittest4(t_test *test)
{
	mt_assert(ft_strncmp("ab\0cde", "abcc\0e", 20) != 0);
}

static void unittest5(t_test *test)
{
	mt_assert(ft_strncmp("q", "a", 0) == strncmp("q", "a", 0));
}

void	suite_00_part1_ft_strncmp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
	SUITE_ADD_TEST(suite, unittest4);
	SUITE_ADD_TEST(suite, unittest5);
}

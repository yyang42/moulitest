#include <project.h>

static void test1(t_test *test)
{
	mt_assert(ft_strequ("", "") == 1);
}

static void test2(t_test *test)
{
	mt_assert(ft_strequ("abcDEF", "abcDEF") == 1);
}

static void test3(t_test *test)
{
	mt_assert(ft_strequ("abcDEF", "abcDEf") == 0);
}

void	suite_01_part2_ft_strequ(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
}

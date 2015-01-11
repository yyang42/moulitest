#include <project.h>

static void test1(t_test *test)
{
	mt_assert(ft_strnequ("ededeqdf", "", 0) == 1);
}

static void test2(t_test *test)
{
	mt_assert(ft_strnequ("abcde", "abdfe", 2) == 1);
}

static void test3(t_test *test)
{
	mt_assert(ft_strnequ("abc", "abc", 100) == 1);
}

static void test4(t_test *test)
{
	mt_assert(ft_strnequ("abcde", "abdde", 5) == 0);
}

void	suite_01_part2_ft_strnequ(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
	SUITE_ADD_TEST(suite, test4);
}

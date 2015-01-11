#include <project.h>

static char	*str = "Un jour je serai, le meilleur dresseur !";

static void test1(t_test *test)
{
	mt_assert(ft_strsub(str, 0, (size_t)-10) == NULL);
}

static void test2(t_test *test)
{
	mt_assert(strcmp(ft_strsub(str, 8, 8), "je serai") == 0);
}

static void test3(t_test *test)
{
	mt_assert(strcmp(ft_strsub(str, 0, 0), "") == 0);
}

void	suite_01_part2_ft_strsub(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
}

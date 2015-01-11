#include <project.h>

static void test1(t_test *test)
{
	mt_assert(strcmp(ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t"), "AAA \t BBB") == 0);
}

static void test2(t_test *test)
{
	mt_assert(strcmp(ft_strtrim("\t\t\n\t\t   "), "") == 0);
}

static void test3(t_test *test)
{
	mt_assert(strcmp(ft_strtrim(""), "") == 0);
}

static void test4(t_test *test)
{
	mt_assert(strcmp(ft_strtrim("abc"), "abc") == 0);
}

void	suite_01_part2_ft_strtrim(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
	SUITE_ADD_TEST(suite, test4);
}

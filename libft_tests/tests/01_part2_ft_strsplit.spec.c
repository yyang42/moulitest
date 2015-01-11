#include <project.h>
#include <limits.h>

static char	**tt;

static void test1(t_test *test)
{
	tt = ft_strsplit("***salut****!**", '*');
	mt_assert(strcmp(tt[0], "salut") == 0);
	mt_assert(strcmp(tt[1], "!") == 0);
	mt_assert(tt[2] == NULL);
}

static void test2(t_test *test)
{
	tt = ft_strsplit("*****", '*');
	mt_assert(tt[0] == NULL);
}

static void test3(t_test *test)
{
	tt = ft_strsplit("coucou", '*');
	mt_assert(strcmp(tt[0], "coucou") == 0);
	mt_assert(tt[1] == NULL);
}

static void test4(t_test *test)
{
	tt = ft_strsplit("salut****", '*');
	mt_assert(strcmp(tt[0], "salut") == 0);
	mt_assert(tt[1] == NULL);
}

static void test5(t_test *test)
{
	tt = ft_strsplit("****salut", '*');
	mt_assert(strcmp(tt[0], "salut") == 0);
	mt_assert(tt[1] == NULL);
}

static void test6(t_test *test)
{
	tt = ft_strsplit("", '*');
	mt_assert(tt &&  tt[0] == NULL);
}

void	suite_01_part2_ft_strsplit(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
	SUITE_ADD_TEST(suite, test4);
	SUITE_ADD_TEST(suite, test5);
	SUITE_ADD_TEST(suite, test6);
}

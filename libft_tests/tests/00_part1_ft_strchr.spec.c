#include <project.h>

static char	buf[] = "Je suis un poisson.";

static void unittest1(t_test *test)
{
	mt_assert(strchr(buf, 'p') == ft_strchr(buf, 'p'));
}

static void unittest2(t_test *test)
{
	mt_assert(strchr(buf, 0) == ft_strchr(buf, 0));
}

static void unittest3(t_test *test)
{
	mt_assert(ft_strchr(buf, 'J') == buf);
}

static void unittest4(t_test *test)
{
	mt_assert(ft_strchr(buf, 'z') == 0);
}

void	suite_00_part1_ft_strchr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
	SUITE_ADD_TEST(suite, unittest4);
}

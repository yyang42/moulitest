#include <project.h>
#include <limits.h>

static void test1(t_test *test)
{
	char	*str;
	char	*t;

	str = ft_strnew(100);
	t = malloc(101);
	bzero(t, 101);
	mt_assert(memcmp(str, t, 101) == 0);
}

static void test2(t_test *test)
{
	mt_assert(ft_strnew(0) != NULL);
}

static void test3(t_test *test)
{
	mt_assert(ft_strnew(ULONG_MAX - 1) == 0);
}

void	suite_01_part2_ft_strnew(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
}

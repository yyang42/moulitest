#include <project.h>

static void unittest1(t_test *test)
{
	char	b1[100], b2[100];

	ft_memset(b1, 42, 100);
	memset(b2, 42, 100);
	mt_assert(memset(b1, 99, 0) == ft_memset(b1, 99, 0));
	mt_assert(memcmp(b1, b2, 100) == 0);
	b1[0] = 1;
	ft_memset(b1, 0, 0);
	mt_assert(b1[0] == 1);
}

static void unittest2(t_test *test)
{
	mt_assert(memcmp(memset(strdup("abcd"), 'A', 5), ft_memset(strdup("abcd"), 'A', 5), 5) == 0);
}

static void unittest3(t_test *test)
{	
	mt_assert(memcmp(memset(strdup("abcd"), 0, 0), ft_memset(strdup("abcd"), 0, 0), 5) == 0);
}

void	suite_00_part1_ft_memset(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
}

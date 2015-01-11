#include <project.h>

static void unittest1(t_test *test)
{
	char	b1[100], b2[100];

	memset(b1, 33, 100);
	memset(b2, 63, 100);

	ft_memcpy(b1, b2, 100);
	mt_assert(memcmp(b1, b2, 100) == 0);
	mt_assert(ft_memcpy(b1, b2, 0) == b1);
}

void	suite_00_part1_ft_memcpy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
}

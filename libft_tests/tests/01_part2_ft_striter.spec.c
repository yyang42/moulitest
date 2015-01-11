#include <project.h>

static void simple_test(t_test *test)
{
	char	str[] = "aBcDeF";

	ft_striter(str, it_test);
	mt_assert(strcmp(str, "bCdEfG") == 0);
}

void	suite_01_part2_ft_striter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

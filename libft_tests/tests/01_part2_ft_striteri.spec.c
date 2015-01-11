#include <project.h>

static void simple_test(t_test *test)
{
	char	str[] = "aBcDeF";

	ft_striteri(str, iti_test);
	mt_assert(strcmp(str, "aCeGiK") == 0);
}

void	suite_01_part2_ft_striteri(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

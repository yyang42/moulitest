#include <project.h>

static void simple_test(t_test *test)
{
	char	*str;

	str = malloc(123);
	ft_strdel(&str);
	mt_assert(str == NULL);
}

void	suite_01_part2_ft_strdel(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

#include <project.h>

static void simple_test(t_test *test)
{
	char	str[] = "tttttt";

	ft_strclr(str);
	mt_assert(memcmp(str, "\0\0\0\0\0\0", 7) == 0);
}

void	suite_01_part2_ft_strclr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

#include <project.h>

static void unittest1(t_test *test)
{
	char	buf[9];

	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");
	mt_assert(strcmp(buf, "Bonjour.") == 0);
	mt_assert(buf == ft_strcat(buf, ""));
}

void	suite_00_part1_ft_strcat(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
}

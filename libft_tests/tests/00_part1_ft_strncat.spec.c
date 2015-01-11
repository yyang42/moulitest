#include <project.h>

static void unittest1(t_test *test)
{
	char	buf[20];

	strcpy(buf, "To be ");
	ft_strncat(buf, "or not to be", 6);
	mt_assert(strcmp(buf, "To be or not") == 0);
}

static void unittest2(t_test *test)
{
	char	buf[20];

	strcpy(buf, "To be ");
	ft_strncat(buf, "or not to be", 6);
	ft_strncat(buf, "efefef", 0);
	mt_assert(strcmp(buf, "To be or not") == 0);
	mt_assert(buf == ft_strncat(buf, "", 0));
}

void	suite_00_part1_ft_strncat(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
}

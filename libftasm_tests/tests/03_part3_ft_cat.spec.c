#include <project.h>

static void simple_test(t_test *test)
{
	mt_assert(0);
}

void	suite_03_part3_ft_cat(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

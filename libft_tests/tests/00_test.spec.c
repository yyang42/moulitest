#include <project.h>

static void simple_string(t_test *test)
{
	// test->debug = 1;
	mt_assert(0);
}

void	suite_00_test(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}

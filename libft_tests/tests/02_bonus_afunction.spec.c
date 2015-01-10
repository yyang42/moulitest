#include <project.h>

static void simple_string(t_test *test)
{
	// test->debug = 1;
	mt_assert(0);
}

static void simple_string2(t_test *test)
{
	// test->debug = 1;
	mt_assert(1);
}

void	suite_02_bonus_afunction(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
	SUITE_ADD_TEST(suite, simple_string2);
}

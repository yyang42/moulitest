#include <project.h>
#include <limits.h>
#include <signal.h>

static void wildcard_for_min_width_positive(t_test *test)
{
	// test->debug = 1;
	assert_printf("%*.*d", 0, 3, 0);
}

void	suite_bonus_02_wildcard_multi(t_suite *suite)
{
	SUITE_ADD_TEST(suite, wildcard_for_min_width_positive);
}

#include <project.h>
#include <limits.h>
#include <signal.h>

static void wildcard_for_min_width(t_test *test)
{
	// test->debug = 1;
	assert_printf("%*d", 5, 42);
}

void	suite_bonus_01_wildcard(t_suite *suite)
{
	SUITE_ADD_TEST(suite, wildcard_for_min_width);
}

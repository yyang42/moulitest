#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%*Z}", -15, 123);
}

void	suite_53_min_width_empty_conv(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}

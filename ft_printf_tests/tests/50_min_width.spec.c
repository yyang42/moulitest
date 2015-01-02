#include <project.h>
#include <limits.h>
#include <signal.h>

static void simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%10d}", 42);
}

static void min_width_smaller_than_input(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%4d}", 10000);
}

static void min_width_larger_than_input(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%30d}", 10000);
}

static void negative_width(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%10d}", -42);
}

void	suite_50_min_width(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, min_width_smaller_than_input);
	SUITE_ADD_TEST(suite, min_width_larger_than_input);
	SUITE_ADD_TEST(suite, negative_width);
}

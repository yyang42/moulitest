#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%-10d}", 42);
}

static void test_min_width_smaller_than_input(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%-4d}", 10000);
}

static void test_min_width_larger_than_input(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%-30d}", 10000);
}

void	suite_51_min_width_flag_minus(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_min_width_smaller_than_input);
	SUITE_ADD_TEST(suite, test_min_width_larger_than_input);
}

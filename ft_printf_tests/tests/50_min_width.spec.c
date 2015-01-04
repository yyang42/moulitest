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

static void min_width_negative_width(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%10d}", -42);
}

static void min_width_c(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%3c}", 0);
}

static void pZero_3MinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%3p}", 0);
}

static void pZero_minus15MinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%*p}", -15, 0);
}

static void invalidConvSpec_withMinWith(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%10R}");
}

void	suite_50_min_width(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, min_width_smaller_than_input);
	SUITE_ADD_TEST(suite, min_width_larger_than_input);
	SUITE_ADD_TEST(suite, min_width_negative_width);
	SUITE_ADD_TEST(suite, min_width_c);
	SUITE_ADD_TEST(suite, pZero_3MinWidth);
	SUITE_ADD_TEST(suite, pZero_minus15MinWidth);
	SUITE_ADD_TEST(suite, invalidConvSpec_withMinWith);
}

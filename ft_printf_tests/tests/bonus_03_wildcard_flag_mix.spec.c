#include <project.h>
#include <limits.h>
#include <signal.h>

static void digit_wildcard_and_min_width_value1(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%3*d}", 0, 0);
}

static void digit_wildcard_and_min_width_value2(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%*3d}", 0, 0);
}

static void digit_wildcard_and_min_width_value3(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%*3d}", 5, 0);
}
static void digit_wildcard_negativePrecision(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%05.*d}", -15, 42);
}

void	suite_bonus_03_wildcard_flag_mix(t_suite *suite)
{
	SUITE_ADD_TEST(suite, digit_wildcard_and_min_width_value1);
	SUITE_ADD_TEST(suite, digit_wildcard_and_min_width_value2);
	SUITE_ADD_TEST(suite, digit_wildcard_and_min_width_value3);
	SUITE_ADD_TEST(suite, digit_wildcard_negativePrecision);
}

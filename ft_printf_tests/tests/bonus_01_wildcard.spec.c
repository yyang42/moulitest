#include <project.h>
#include <limits.h>
#include <signal.h>

static void wildcard_for_min_width_positive(t_test *test)
{
	// test->debug = 1;
	assert_printf("%*d", 5, 42);
}

static void wildcard_for_min_width_negative(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%*d}", -5, 42);
}

static void wildcard_for_min_width_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%*d}", 0, 42);
}

static void wildcard_for_precision_positive(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%.*d}", 5, 42);
}

static void wildcard_for_precision_negative(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%.*d}", -5, 42);
}

static void wildcard_for_precision_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%.*d}", 0, 42);
}

static void wildcard_for_precision_string_positive(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%.*s}", 5, "42");
}

static void wildcard_for_precision_string_negative(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%.*s}", -5, "42");
}

static void wildcard_for_precision_string_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%.*s}", 0, "42");
}

void	suite_bonus_01_wildcard(t_suite *suite)
{
	SUITE_ADD_TEST(suite, wildcard_for_min_width_positive);
	SUITE_ADD_TEST(suite, wildcard_for_min_width_negative);
	SUITE_ADD_TEST(suite, wildcard_for_min_width_zero);
	SUITE_ADD_TEST(suite, wildcard_for_precision_positive);
	SUITE_ADD_TEST(suite, wildcard_for_precision_negative);
	SUITE_ADD_TEST(suite, wildcard_for_precision_zero);
	SUITE_ADD_TEST(suite, wildcard_for_precision_string_positive);
	SUITE_ADD_TEST(suite, wildcard_for_precision_string_negative);
	SUITE_ADD_TEST(suite, wildcard_for_precision_string_zero);
}

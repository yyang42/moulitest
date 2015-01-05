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

static void wildcard_for_min_width_c_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%*c}", 0, 0);
}

static void c_minWidthNegative_zeroValue(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%*c}", -15, 0);
}

static void wildcard_for_precision_digit_positive(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%.*d}", 5, 42);
}

static void wildcard_for_precision_digit_negative(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%.*d}", -5, 42);
}

static void wildcard_for_precision_digit_zero(t_test *test)
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

static void sNullString_zeroMinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%*s}", 5, 0);
}
static void pointer_wildcard(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%3*p}", 10, 0);
}

void	suite_bonus_01_wildcard(t_suite *suite)
{
	SUITE_ADD_TEST(suite, wildcard_for_min_width_positive);
	SUITE_ADD_TEST(suite, wildcard_for_min_width_negative);
	SUITE_ADD_TEST(suite, wildcard_for_min_width_zero);
	SUITE_ADD_TEST(suite, wildcard_for_min_width_c_zero);
	SUITE_ADD_TEST(suite, c_minWidthNegative_zeroValue);
	SUITE_ADD_TEST(suite, wildcard_for_precision_digit_positive);
	SUITE_ADD_TEST(suite, wildcard_for_precision_digit_negative);
	SUITE_ADD_TEST(suite, wildcard_for_precision_digit_zero);
	SUITE_ADD_TEST(suite, wildcard_for_precision_string_positive);
	SUITE_ADD_TEST(suite, wildcard_for_precision_string_negative);
	SUITE_ADD_TEST(suite, wildcard_for_precision_string_zero);
	SUITE_ADD_TEST(suite, sNullString_zeroMinWidth);
	SUITE_ADD_TEST(suite, pointer_wildcard);
}

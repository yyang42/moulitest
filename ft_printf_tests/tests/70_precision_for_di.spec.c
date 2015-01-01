#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_precision_d(t_test *test)
{
	// debug_next_assert();
	assert_printf("%.4d", 42);
}

static void test_precision_d_higher_min_width(t_test *test)
{
	// debug_next_assert();
	assert_printf("%15.4d", 42);
}

static void test_precision_d_higher_precision(t_test *test)
{
	// debug_next_assert();
	assert_printf("%4.15d", 42);
}

static void test_precision_d_zero_value(t_test *test)
{
	// debug_next_assert();
	assert_printf("%.d, %.0d", 0, 0);
}

static void test_precision_i(t_test *test)
{
	// debug_next_assert();
	assert_printf("%.4i", 42);
}

static void test_precision_i_higher_min_width(t_test *test)
{
	// debug_next_assert();
	assert_printf("%15.4i", 42);
}

static void test_precision_i_higher_precision(t_test *test)
{
	// debug_next_assert();
	assert_printf("%4.15i", 42);
}

static void test_precision_i_zero_value(t_test *test)
{
	// debug_next_assert();
	assert_printf("%.i, %.0i", 0, 0);
}

// static void test_precision_empty(t_test *test)
// {
// 	debug_next_assert();
// 	assert_printf("%.d", 0);
// }

// static void test_precision_zero(t_test *test)
// {
// 	debug_next_assert();
// 	assert_printf("%.0d", 0);
// }

// static void test_precision_octal(t_test *test)
// {
// 	debug_next_assert();
// 	assert_printf("%#.o", 42);
// }

// static void test_precision_octal_zero(t_test *test)
// {
// 	debug_next_assert();
// 	assert_printf("%#.o", 0);
// }

// static void test_precision_hex(t_test *test)
// {
// 	debug_next_assert();
// 	assert_printf("%#.x", 42);
// }

// static void test_precision_hex_zero(t_test *test)
// {
// 	debug_next_assert();
// 	assert_printf("%#.x", 0);
// }

void	suite_70_precision_for_di(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_precision_d);
	SUITE_ADD_TEST(suite, test_precision_d_higher_min_width);
	SUITE_ADD_TEST(suite, test_precision_d_higher_precision);
	SUITE_ADD_TEST(suite, test_precision_d_zero_value);
	SUITE_ADD_TEST(suite, test_precision_i);
	SUITE_ADD_TEST(suite, test_precision_i_higher_min_width);
	SUITE_ADD_TEST(suite, test_precision_i_higher_precision);
	SUITE_ADD_TEST(suite, test_precision_i_zero_value);
	// SUITE_ADD_TEST(suite, test_precision_empty);
	// SUITE_ADD_TEST(suite, test_precision_zero);
	// SUITE_ADD_TEST(suite, test_precision_octal);
	// SUITE_ADD_TEST(suite, test_precision_octal_zero);
	// SUITE_ADD_TEST(suite, test_precision_hex);
	// SUITE_ADD_TEST(suite, test_precision_hex_zero);
}

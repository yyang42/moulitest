#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_precision_d(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.4d", 42);
}

static void test_precision_d_higher_min_width(t_test *test)
{
	// test->debug = 1;
	assert_printf("%15.4d", 42);
}

static void test_precision_d_higher_precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%4.15d", 42);
}

static void test_precision_d_zero_value(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.d, %.0d", 0, 0);
}

static void test_precision_d_negative_value(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.10d", -42);
}

static void test_precision_i(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.4i", 42);
}

static void test_precision_i_higher_min_width(t_test *test)
{
	// test->debug = 1;
	assert_printf("%15.4i", 42);
}

static void test_precision_i_higher_precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%4.15i", 42);
}

static void test_precision_i_zero_value(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.i, %.0i", 0, 0);
}

static void test_precision_u(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.4u", 42);
}

static void test_precision_u_higher_min_width(t_test *test)
{
	// test->debug = 1;
	assert_printf("%15.4u", 42);
}

static void test_precision_u_higher_precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%4.15u", 42);
}

static void test_precision_u_zero_value(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.u, %.0u", 0, 0);
}

void	suite_70_precision_for_diu(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_precision_d);
	SUITE_ADD_TEST(suite, test_precision_d_higher_min_width);
	SUITE_ADD_TEST(suite, test_precision_d_higher_precision);
	SUITE_ADD_TEST(suite, test_precision_d_zero_value);
	SUITE_ADD_TEST(suite, test_precision_d_negative_value);
	SUITE_ADD_TEST(suite, test_precision_i);
	SUITE_ADD_TEST(suite, test_precision_i_higher_min_width);
	SUITE_ADD_TEST(suite, test_precision_i_higher_precision);
	SUITE_ADD_TEST(suite, test_precision_i_zero_value);
	SUITE_ADD_TEST(suite, test_precision_u);
	SUITE_ADD_TEST(suite, test_precision_u_higher_min_width);
	SUITE_ADD_TEST(suite, test_precision_u_higher_precision);
	SUITE_ADD_TEST(suite, test_precision_u_zero_value);
}

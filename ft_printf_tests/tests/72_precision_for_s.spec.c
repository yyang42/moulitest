#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_precision_s(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.4s", "42");
}

static void test_precision_s_higher_min_width(t_test *test)
{
	// test->debug = 1;
	assert_printf("%15.4s", "42");
}

static void test_precision_s_higher_precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%4.15s", "42");
}

void	suite_72_precision_for_s(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_precision_s);
	SUITE_ADD_TEST(suite, test_precision_s_higher_min_width);
	SUITE_ADD_TEST(suite, test_precision_s_higher_precision);
}

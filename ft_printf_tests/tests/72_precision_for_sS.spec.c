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

static void test_precision_s_implicit_precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%4.s", "42");
}

static void test_precision_S(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.4S", L"我是一只猫。");
}

static void test_precision_S_higher_min_width(t_test *test)
{
	// test->debug = 1;
	assert_printf("%15.4S", L"我是一只猫。");
}

static void test_precision_S_higher_precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%4.15S", L"我是一只猫。");
}

static void test_precision_S_implicit_precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%4.S", L"我是一只猫。");
}

static void test_precision_S_higher_precision_ascii(t_test *test)
{
	// test->debug = 1;
	assert_printf("%4.1S", L"Jambon");
}

void	suite_72_precision_for_sS(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_precision_s);
	SUITE_ADD_TEST(suite, test_precision_s_higher_min_width);
	SUITE_ADD_TEST(suite, test_precision_s_higher_precision);
	SUITE_ADD_TEST(suite, test_precision_s_implicit_precision);
	SUITE_ADD_TEST(suite, test_precision_S);
	SUITE_ADD_TEST(suite, test_precision_S_higher_min_width);
	SUITE_ADD_TEST(suite, test_precision_S_higher_precision);
	SUITE_ADD_TEST(suite, test_precision_S_implicit_precision);
	SUITE_ADD_TEST(suite, test_precision_S_higher_precision_ascii);
}

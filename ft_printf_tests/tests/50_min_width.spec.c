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

static void pZero_5MinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%5p}", 0);
}

static void pZero_minus15MinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%-15p}", 0);
}

static void pZero_minus13MinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%-13p}", &strlen);
}


static void pZero_minus12MinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%-12p}", &strlen);
}

static void invalidConvSpec_withMinWith(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%10R}");
}

static void wideString(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%30S}", L"我是一只猫。");
}

static void wideString_minusMinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%-30S}", L"我是一只猫。");
}

void	suite_50_min_width(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, min_width_smaller_than_input);
	SUITE_ADD_TEST(suite, min_width_larger_than_input);
	SUITE_ADD_TEST(suite, min_width_negative_width);
	SUITE_ADD_TEST(suite, min_width_c);
	SUITE_ADD_TEST(suite, pZero_5MinWidth);
	SUITE_ADD_TEST(suite, pZero_minus15MinWidth);
	SUITE_ADD_TEST(suite, pZero_minus13MinWidth);
	SUITE_ADD_TEST(suite, pZero_minus12MinWidth);
	SUITE_ADD_TEST(suite, invalidConvSpec_withMinWith);
	SUITE_ADD_TEST(suite, wideString);
	SUITE_ADD_TEST(suite, wideString_minusMinWidth);
}

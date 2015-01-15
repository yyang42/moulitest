#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%010d}", 42);
}
static void test_negative_value(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%010d}", -42);
}

static void test_min_width_smaller_than_input(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%04d}", 10000);
}

static void test_min_width_larger_than_input(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%030d}", 10000);
}

static void test_min_width_with_hexa(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%030x}", 0xFFFF);
}

static void test_min_width_with_hexa_caps(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%030X}", 0xFFFF);
}

static void char_posMinWidth_zeroFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%03c}", 0);
}

static void str_posMinWidth_zeroFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%05s}", "abc");
}

static void wide_str_posMinWidth_zeroFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%030S}", L"我是一只猫。");
}

static void pointer_posMinWidth_zeroFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%05p}", 0);
}

static void pointer_valueLargerThanMinWidth_zeroFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%05p}", &pointer_valueLargerThanMinWidth_zeroFlag);
}

void	suite_52_min_width_flag_zero(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_negative_value);
	SUITE_ADD_TEST(suite, test_min_width_smaller_than_input);
	SUITE_ADD_TEST(suite, test_min_width_larger_than_input);
	SUITE_ADD_TEST(suite, test_min_width_with_hexa);
	SUITE_ADD_TEST(suite, test_min_width_with_hexa_caps);
	SUITE_ADD_TEST(suite, char_posMinWidth_zeroFlag);
	SUITE_ADD_TEST(suite, str_posMinWidth_zeroFlag);
	SUITE_ADD_TEST(suite, wide_str_posMinWidth_zeroFlag);
	SUITE_ADD_TEST(suite, pointer_posMinWidth_zeroFlag);
	SUITE_ADD_TEST(suite, pointer_valueLargerThanMinWidth_zeroFlag);
}

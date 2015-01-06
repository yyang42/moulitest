#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_precision_o_sharp_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#.o, %#.0o", 0, 0);
}

static void test_precision_x_sharp_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#.x, %#.0x", 0, 0);
}

static void test_precision_p_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.p, %.0p", 0, 0);
}

static void char_precision_minwdith_and_flagZero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%05.c}", 0);
}

static void string_precision_minwdith_and_flagZero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%05.s}", 0);
}

static void percent_precision_minwdith_and_flagZero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%05.%}", 0);
}

static void nonValidConvSpec_precision_minwdith_and_flagZero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%05.Z}", 0);
}

static void hex_precision_and_flagSharp(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%#.5x}", 1);
}

static void octal_precision_and_flagSharp(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#.3o", 1);
}

static void wideString_precisionMinWidth_flagZero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%05.S}", L"42 c est cool");
}

void	suite_79_precision_mixed_with_flags(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_precision_o_sharp_zero);
	SUITE_ADD_TEST(suite, test_precision_x_sharp_zero);
	SUITE_ADD_TEST(suite, test_precision_p_zero);
	SUITE_ADD_TEST(suite, char_precision_minwdith_and_flagZero);
	SUITE_ADD_TEST(suite, string_precision_minwdith_and_flagZero);
	SUITE_ADD_TEST(suite, percent_precision_minwdith_and_flagZero);
	SUITE_ADD_TEST(suite, nonValidConvSpec_precision_minwdith_and_flagZero);
	SUITE_ADD_TEST(suite, hex_precision_and_flagSharp);
	SUITE_ADD_TEST(suite, octal_precision_and_flagSharp);
	SUITE_ADD_TEST(suite, wideString_precisionMinWidth_flagZero);
}

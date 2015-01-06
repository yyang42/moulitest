#include <project.h>
#include <limits.h>
#include <signal.h>

static void positiveDigit_flagsSpacePlus_spaceFirst(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% +d}", 42);
}

static void positiveDigit_flagsSpacePlus_plusFirst(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%+ d}", 42);
}

static void mix_plus_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%+03d}", 0);
}

static void mix_space_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% 03d}", 0);
}

static void zeroFlag_minusMinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%0-3d}", 0);
}


static void zeroFlag_plusFlag_minWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%+03d}", 12);
}

static void zeroFlag_plusFlag_largeMinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%+03d}", 123456);
}

static void mix_zeroFlag_minWidth_precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%03.2d}", 0);
}

static void octalUppercase_precision_sharpFlag_zeroValue(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#.O", 0);
}

void	suite_69_flag_mix(t_suite *suite)
{
	SUITE_ADD_TEST(suite, positiveDigit_flagsSpacePlus_spaceFirst);
	SUITE_ADD_TEST(suite, positiveDigit_flagsSpacePlus_plusFirst);
	SUITE_ADD_TEST(suite, mix_plus_zero);
	SUITE_ADD_TEST(suite, mix_space_zero);
	SUITE_ADD_TEST(suite, zeroFlag_minusMinWidth);
	SUITE_ADD_TEST(suite, zeroFlag_plusFlag_minWidth);
	SUITE_ADD_TEST(suite, zeroFlag_plusFlag_largeMinWidth);
	SUITE_ADD_TEST(suite, mix_zeroFlag_minWidth_precision);
	SUITE_ADD_TEST(suite, octalUppercase_precision_sharpFlag_zeroValue);
}

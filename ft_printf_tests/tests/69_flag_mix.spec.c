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

static void test1(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%+03d}", 12);
}

static void test2(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%+03d}", 123456);
}

void	suite_69_flag_mix(t_suite *suite)
{
	SUITE_ADD_TEST(suite, positiveDigit_flagsSpacePlus_spaceFirst);
	SUITE_ADD_TEST(suite, positiveDigit_flagsSpacePlus_plusFirst);
	SUITE_ADD_TEST(suite, mix_plus_zero);
	SUITE_ADD_TEST(suite, mix_space_zero);
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
}

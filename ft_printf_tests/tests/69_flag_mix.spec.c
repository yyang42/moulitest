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

void	suite_69_flag_mix(t_suite *suite)
{
	SUITE_ADD_TEST(suite, positiveDigit_flagsSpacePlus_spaceFirst);
	SUITE_ADD_TEST(suite, positiveDigit_flagsSpacePlus_plusFirst);
}

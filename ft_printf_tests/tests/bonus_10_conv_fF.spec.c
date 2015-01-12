#include <project.h>
#include <limits.h>
#include <signal.h>

static void simple_small_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%F}", 1.42, 1.42);
}

static void simple_negative_small_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%F}", -1.42, -1.42);
}

static void simple_large_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%F}", 1444565444646.6465424242242, 1444565444646.6465424242242);
}

static void simple_negative_large_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%F}", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
}

void	suite_bonus_10_conv_fF(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_small_nbr);
	SUITE_ADD_TEST(suite, simple_negative_small_nbr);
	SUITE_ADD_TEST(suite, simple_large_nbr);
	SUITE_ADD_TEST(suite, simple_negative_large_nbr);
}

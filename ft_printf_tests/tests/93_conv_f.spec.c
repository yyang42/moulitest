#include <project.h>
#include <limits.h>
#include <signal.h>

static void simple_small_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
}

static void simple_negative_small_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l);
}

static void simple_large_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%lf}{%Lf}", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
}

static void simple_negative_large_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%lf}{%Lf}", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
}

void	suite_93_conv_f(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_small_nbr);
	SUITE_ADD_TEST(suite, simple_negative_small_nbr);
	SUITE_ADD_TEST(suite, simple_large_nbr);
	SUITE_ADD_TEST(suite, simple_negative_large_nbr);
}

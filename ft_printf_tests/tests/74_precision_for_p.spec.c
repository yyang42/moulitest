#include <project.h>
#include <limits.h>
#include <signal.h>

static void pNullPointer_zeroPrecision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.0p, %.p", 0, 0);
}

static void pNullPointer_3Precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.5p", 0);
}

void	suite_74_precision_for_p(t_suite *suite)
{
	SUITE_ADD_TEST(suite, pNullPointer_zeroPrecision);
	SUITE_ADD_TEST(suite, pNullPointer_3Precision);
}

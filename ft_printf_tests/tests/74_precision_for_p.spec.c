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

static void Pointer_Precision_width_len_between_width_prec(t_test *test)
{
	// test->debug = 1;
	assert_printf("%9.2p", 1234);
}

static void Pointer_Precision_width_len_higher_width(t_test *test)
{
	// test->debug = 1;
	assert_printf("%9.2p", 1234567);
}

static void Pointer_Precision_width_min_len_between_width_prec(t_test *test)
{
	// test->debug = 1;
	assert_printf("%2.9p", 1234);
}

static void Pointer_Precision_width_min_len_higher_prec(t_test *test)
{
	// test->debug = 1;
	assert_printf("%2.9p", 1234567);
}

void	suite_74_precision_for_p(t_suite *suite)
{
	SUITE_ADD_TEST(suite, pNullPointer_zeroPrecision);
	SUITE_ADD_TEST(suite, pNullPointer_3Precision);
	SUITE_ADD_TEST(suite, Pointer_Precision_width_len_between_width_prec);
	SUITE_ADD_TEST(suite, Pointer_Precision_width_len_higher_width);
	SUITE_ADD_TEST(suite, Pointer_Precision_width_min_len_between_width_prec);
	SUITE_ADD_TEST(suite, Pointer_Precision_width_min_len_higher_prec);
}

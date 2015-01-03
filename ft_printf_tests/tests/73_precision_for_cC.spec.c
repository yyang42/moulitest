#include <project.h>
#include <limits.h>
#include <signal.h>

static void cNullChar(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.c", 0);
}

static void cNullChar_positivePrecision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.5c", 0);
}

static void cPositiveValue_positivePrecision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.5c", 42);
}

void	suite_73_precision_for_cC(t_suite *suite)
{
	SUITE_ADD_TEST(suite, cNullChar);
	SUITE_ADD_TEST(suite, cNullChar_positivePrecision);
	SUITE_ADD_TEST(suite, cPositiveValue_positivePrecision);
}

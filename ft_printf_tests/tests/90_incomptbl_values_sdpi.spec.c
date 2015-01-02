#include <project.h>
#include <limits.h>

static void test_hhd(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhd - %hhd", SHRT_MAX - 42,  SHRT_MAX - 4200);
}

static void test_zi(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zi", LLONG_MIN);
}

static void test_zd(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zd", LLONG_MIN);
}

static void test_p_incompatible_flags(t_test *test)
{
	// test->debug = 1;
	assert_printf("% p|%+p", 42, 42);
}

void	suite_90_incomptbl_values_sdpi(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_hhd);
	SUITE_ADD_TEST(suite, test_zi);
	SUITE_ADD_TEST(suite, test_zd);
	SUITE_ADD_TEST(suite, test_p_incompatible_flags);
}

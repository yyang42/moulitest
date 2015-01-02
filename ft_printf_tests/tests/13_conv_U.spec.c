#include <project.h>
#include <limits.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%U", 42);
}

static void test_ulong_max_half(t_test *test)
{
	// test->debug = 1;
	assert_printf("%U", ULONG_MAX / 2);
}

static void test_ulong_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%U", ULONG_MAX);
}

void	suite_13_conv_U(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_ulong_max_half);
	SUITE_ADD_TEST(suite, test_ulong_max);
}

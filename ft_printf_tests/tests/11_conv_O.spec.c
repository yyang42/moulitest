#include <project.h>
#include <limits.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%O", 42);
}

static void test_long_octal_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("before %O after", 42);
}

static void test_many_long_octals(t_test *test)
{
	// test->debug = 1;
	assert_printf("%O%O%O%O%O",
		1, 100, 999, 42, 999988888);
}

static void test_many_long_octals_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("a%Ob%Oc%Od",
		0, 55555, 100000);
}

static void test_octal_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%O", LONG_MAX);
}

void	suite_11_conv_O(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_long_octal_with_strings);
	SUITE_ADD_TEST(suite, test_many_long_octals);
	SUITE_ADD_TEST(suite, test_many_long_octals_with_strings);
	SUITE_ADD_TEST(suite, test_octal_long_max);
}

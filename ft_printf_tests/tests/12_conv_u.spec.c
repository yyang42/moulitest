#include <project.h>
#include <limits.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%u", 42);
}

static void test_uint_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("before %u after", 42);
}

static void test_many_uints(t_test *test)
{
	// test->debug = 1;
	assert_printf("%u%u%u%u%u",
		1, 100, 999, 42, 999988888);
}

static void test_many_uints_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("a%ub%uc%ud",
		0, 55555, 100000);
}

static void test_uints_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%u", UINT_MAX);
}

void	suite_12_conv_u(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_uint_with_strings);
	SUITE_ADD_TEST(suite, test_many_uints);
	SUITE_ADD_TEST(suite, test_many_uints_with_strings);
	SUITE_ADD_TEST(suite, test_uints_max);
}

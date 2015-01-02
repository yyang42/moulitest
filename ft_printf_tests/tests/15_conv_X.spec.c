#include <project.h>
#include <limits.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%X", 42);
}

static void test_hex_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("before %X after", 42);
}

static void test_many_hexs(t_test *test)
{
	// test->debug = 1;
	assert_printf("%X%X%X%X%X",
		1, 100, 999, 42, 999988888);
}

static void test_many_hexs_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("a%Xb%Xc%Xd",
		0, 55555, 100000);
}

static void test_uint_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%X, %X", 0, UINT_MAX);
}

void	suite_15_conv_X(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_hex_with_strings);
	SUITE_ADD_TEST(suite, test_many_hexs);
	SUITE_ADD_TEST(suite, test_many_hexs_with_strings);
	SUITE_ADD_TEST(suite, test_uint_max);
}

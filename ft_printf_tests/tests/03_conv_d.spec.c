#include <project.h>
#include <limits.h>

static void test_digit(t_test *test)
{
	// test->debug = 1;
	assert_printf("%d", 42);
}

static void test_digit_negative(t_test *test)
{
	// test->debug = 1;
	assert_printf("%d", -42);
}

static void test_digit_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("before %d after", 42);
}

static void test_many_digits(t_test *test)
{
	// test->debug = 1;
	assert_printf("%d%d%d%d%d",
		1, -2, 3, -4, 5);
}

static void test_many_digits_width_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("a%db%dc%dd",
		1, -2, 3);
}

static void test_int_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%d", INT_MAX);
}

static void test_int_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%d", INT_MIN);
}

void	suite_03_conv_d(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_digit);
	SUITE_ADD_TEST(suite, test_digit_negative);
	SUITE_ADD_TEST(suite, test_digit_with_strings);
	SUITE_ADD_TEST(suite, test_many_digits);
	SUITE_ADD_TEST(suite, test_many_digits_width_strings);
	SUITE_ADD_TEST(suite, test_int_max);
	SUITE_ADD_TEST(suite, test_int_min);
}

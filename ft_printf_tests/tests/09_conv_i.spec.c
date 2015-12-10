#include <project.h>
#include <limits.h>

static void test_digit(t_test *test)
{
	// test->debug = 1;
	assert_printf("%i", 42);
}

static void test_digit_negative(t_test *test)
{
	// test->debug = 1;
	assert_printf("%i", -42);
}

static void test_digit_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("before %i after", 42);
}

static void test_many_digits(t_test *test)
{
	// test->debug = 1;
	assert_printf("%i%i%i%i%i",
		1, -2, 3, -4, 5);
}

static void test_many_digits_width_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("a%ib%ic%id",
		1, -2, 3);
}

static void test_int_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%i", INT_MAX);
}

static void test_int_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%i", INT_MIN);
}

static void test_int_max_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%i", INT_MAX + 1);
}

static void test_int_min_less(t_test *test)
{
	// test->debug = 1;
	assert_printf("%i", INT_MIN - 1);
}

void	suite_09_conv_i(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_digit);
	SUITE_ADD_TEST(suite, test_digit_negative);
	SUITE_ADD_TEST(suite, test_digit_with_strings);
	SUITE_ADD_TEST(suite, test_many_digits);
	SUITE_ADD_TEST(suite, test_many_digits_width_strings);
	SUITE_ADD_TEST(suite, test_int_max);
	SUITE_ADD_TEST(suite, test_int_min);
	SUITE_ADD_TEST(suite, test_int_max_plus);
	SUITE_ADD_TEST(suite, test_int_min_less);
}

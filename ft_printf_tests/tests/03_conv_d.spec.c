#include <project.h>

static void test_digit(t_test *test)
{
	// debug_next_assert();
	assert_printf("%d", 42);
}

static void test_digit_negative(t_test *test)
{
	// debug_next_assert();
	assert_printf("%d", -42);
}

static void test_digit_with_strings(t_test *test)
{
	// debug_next_assert();
	assert_printf("before %d after", 42);
}

static void test_many_digits(t_test *test)
{
	// debug_next_assert();
	assert_printf("%d%d%d%d%d",
		1, -2, 3, -4, 5);
}

static void test_many_digits_width_strings(t_test *test)
{
	// debug_next_assert();
	assert_printf("a%db%dc%dd",
		1, -2, 3);
}

void	suite_03_conv_d(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_digit);
	SUITE_ADD_TEST(suite, test_digit_negative);
	SUITE_ADD_TEST(suite, test_digit_with_strings);
	SUITE_ADD_TEST(suite, test_many_digits);
	SUITE_ADD_TEST(suite, test_many_digits_width_strings);
}

#include <project.h>

static void test_digit(t_test *test)
{
	// debug_on();
	assert_printf("%d", 42);
	// debug_off();
}

static void test_digit_with_strings(t_test *test)
{
	// debug_on();
	assert_printf("before %d after", 42);
	// debug_off();
}

static void test_many_digits(t_test *test)
{
	// debug_on();
	assert_printf("%d%d%d%d%d",
		1, 2, 3, 4, 5);
	// debug_off();
}

static void test_many_digits_width_strings(t_test *test)
{
	// debug_on();
	assert_printf("a%db%dc%dd",
		1, 2, 3);
	// debug_off();
}

void	suite_03_modifier_d(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_digit);
	SUITE_ADD_TEST(suite, test_digit_with_strings);
	SUITE_ADD_TEST(suite, test_many_digits);
	SUITE_ADD_TEST(suite, test_many_digits_width_strings);
}

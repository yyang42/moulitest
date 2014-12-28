#include <project.h>

static void test_digit(t_test *test)
{
	debug_on();
	assert_printf("%d", 42);
	debug_off();
}

static void test_digit_with_strings(t_test *test)
{
	debug_on();
	assert_printf("before %d after", 42);
	debug_off();
}

void	suite_03_modifier_d(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_digit);
	SUITE_ADD_TEST(suite, test_digit_with_strings);
}

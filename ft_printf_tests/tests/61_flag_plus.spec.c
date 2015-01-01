#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_plus_d_simple(t_test *test)
{
	// debug_next_assert();
	assert_printf("%+d", 42);
}

static void test_plus_d_simple_minus(t_test *test)
{
	// debug_next_assert();
	assert_printf("%+d", -42);
}

static void test_plus_i_simple(t_test *test)
{
	// debug_next_assert();
	assert_printf("%+i", 42);
}

static void test_plus_i_simple_minus(t_test *test)
{
	// debug_next_assert();
	assert_printf("%+i", -42);
}

void	suite_61_flag_plus(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_plus_d_simple);
	SUITE_ADD_TEST(suite, test_plus_d_simple_minus);
	SUITE_ADD_TEST(suite, test_plus_i_simple);
	SUITE_ADD_TEST(suite, test_plus_i_simple_minus);
}

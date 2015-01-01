#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_octal_simple(t_test *test)
{
	// debug_next_assert();
	assert_printf("%#o", 42);
}

static void test_octal_max(t_test *test)
{
	// debug_next_assert();
	assert_printf("%#o", INT_MAX);
}

static void test_hex_simple(t_test *test)
{
	// debug_next_assert();
	assert_printf("%#x", 42);
}

static void test_hex_max(t_test *test)
{
	// debug_next_assert();
	assert_printf("%#x", INT_MAX);
}

static void test_hex_uppercase_simple(t_test *test)
{
	// debug_next_assert();
	assert_printf("%#X", 42);
}

static void test_hex_uppercase_max(t_test *test)
{
	// debug_next_assert();
	assert_printf("%#X", INT_MAX);
}

void	suite_50_flag_sharp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_octal_simple);
	SUITE_ADD_TEST(suite, test_octal_max);
	SUITE_ADD_TEST(suite, test_hex_simple);
	SUITE_ADD_TEST(suite, test_hex_max);
	SUITE_ADD_TEST(suite, test_hex_uppercase_simple);
	SUITE_ADD_TEST(suite, test_hex_uppercase_max);
}

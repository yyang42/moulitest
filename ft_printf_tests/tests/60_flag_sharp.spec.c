#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_octal_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#o", 42);
}

static void test_octal_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#o", 0);
}

static void test_octal_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#o", INT_MAX);
}

static void test_octalUppercase_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#O", 1);
}

static void test_hex_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#x", 42);
}

static void test_hex_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#x", 0);
}

static void test_hex_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#x", INT_MAX);
}

static void test_hex_uppercase_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#X", 42);
}

static void test_hex_uppercase_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#X", 0);
}

static void test_hex_uppercase_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#X", INT_MAX);
}

static void test_hex_c_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#c", 0);
}

void	suite_60_flag_sharp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_octal_simple);
	SUITE_ADD_TEST(suite, test_octal_zero);
	SUITE_ADD_TEST(suite, test_octal_max);
	SUITE_ADD_TEST(suite, test_octalUppercase_max);
	SUITE_ADD_TEST(suite, test_hex_simple);
	SUITE_ADD_TEST(suite, test_hex_zero);
	SUITE_ADD_TEST(suite, test_hex_max);
	SUITE_ADD_TEST(suite, test_hex_uppercase_simple);
	SUITE_ADD_TEST(suite, test_hex_uppercase_zero);
	SUITE_ADD_TEST(suite, test_hex_uppercase_max);
	SUITE_ADD_TEST(suite, test_hex_c_zero);
}

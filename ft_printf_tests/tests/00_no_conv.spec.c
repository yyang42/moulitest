#include <project.h>

static void simple_string(t_test *test)
{
	// test->debug = 1;
	assert_printf("This is a simple test.");
}

static void simple_string_with_newline(t_test *test)
{
	// test->debug = 1;
	assert_printf("This is a simple test.\nSecond sentence.\n");
}

static void empty_string(t_test *test)
{
	// test->debug = 1;
	assert_printf("");
}

static void simple_newline(t_test *test)
{
	// test->debug = 1;
	assert_printf("\n");
}

void	suite_00_no_conv(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
	SUITE_ADD_TEST(suite, simple_string_with_newline);
	SUITE_ADD_TEST(suite, empty_string);
	SUITE_ADD_TEST(suite, simple_newline);
}

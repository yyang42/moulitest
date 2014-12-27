#include <fw.h>
#include <test.h>
#include <suite.h>
#include <stdarg.h>
#include <project.h>
#include <capture.h>
#include <unistd.h>


static void simple_string(t_test *test)
{
	assert_printf_noarg("This is a simple test.");
}

static void simple_string_with_newline(t_test *test)
{
	assert_printf_noarg("This is a simple test.\n");
}
static void test_simple_printf00(t_test *test)
{
	assert_printf("aaa", NULL);
}

void	suite_00_no_modifier(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
	SUITE_ADD_TEST(suite, simple_string_with_newline);
	SUITE_ADD_TEST(suite, test_simple_printf00);
}

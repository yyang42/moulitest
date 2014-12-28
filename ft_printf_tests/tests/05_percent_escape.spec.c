#include <project.h>

#include <signal.h>

static void test_percent_alone(t_test *test)
{
	// debug_on();
	assert_printf_noarg("%%");
	// debug_off();
}

static void test_percent_simple(t_test *test)
{
	// debug_on();
	assert_printf_noarg("aa%%bb");
	// debug_off();
}

static void test_many_percent(t_test *test)
{
	// debug_on();
	assert_printf_noarg("%%%%%%%%%%");
	// debug_off();
}

static void test_more_percent(t_test *test)
{
	// debug_on();
	assert_printf_noarg("many many percent :) .%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.%%.");
	// debug_off();
}

void	suite_05_percent_escape(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_percent_alone);
	SUITE_ADD_TEST(suite, test_percent_simple);
	SUITE_ADD_TEST(suite, test_many_percent);
	SUITE_ADD_TEST(suite, test_more_percent);
}

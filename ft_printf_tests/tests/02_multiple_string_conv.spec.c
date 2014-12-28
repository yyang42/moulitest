#include <project.h>

static void test_2_strings(t_test *test)
{
	// debug_on();
	assert_printf("111%s333%s555", "222", "444");
	// debug_off();
}

static void test_more_strings(t_test *test)
{
	// debug_on();
	assert_printf("111%s333%s555%saaa%sccc",
		"222", "444", "666", "bbb");
	// debug_off();
}

void	suite_02_multiple_string_conv(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_2_strings);
	SUITE_ADD_TEST(suite, test_more_strings);
}

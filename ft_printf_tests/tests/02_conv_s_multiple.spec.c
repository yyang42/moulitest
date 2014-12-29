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

static void test_only_string_conv(t_test *test)
{
	// debug_on();
	assert_printf("%s%s%s%s%s",
		"1", "2", "3", "4", "5");
	// debug_off();
}

void	suite_02_conv_s_multiple(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_2_strings);
	SUITE_ADD_TEST(suite, test_more_strings);
	SUITE_ADD_TEST(suite, test_only_string_conv);
}

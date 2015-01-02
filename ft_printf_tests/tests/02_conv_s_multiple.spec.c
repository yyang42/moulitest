#include <project.h>

static void test_2_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("111%s333%s555", "222", "444");
}

static void test_more_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("111%s333%s555%saaa%sccc",
		"222", "444", "666", "bbb");
}

static void test_only_string_conv(t_test *test)
{
	// test->debug = 1;
	assert_printf("%s%s%s%s%s",
		"1", "2", "3", "4", "5");
}

void	suite_02_conv_s_multiple(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_2_strings);
	SUITE_ADD_TEST(suite, test_more_strings);
	SUITE_ADD_TEST(suite, test_only_string_conv);
}

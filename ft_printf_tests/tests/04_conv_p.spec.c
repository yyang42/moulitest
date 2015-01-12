#include <project.h>

static void test_int_pointer(t_test *test)
{
	int i;

	// test->debug = 1;
	assert_printf("%p", &i);
}


static void test_unsigned_long_pointer(t_test *test)
{
	unsigned long l;

	// test->debug = 1;
	assert_printf("%p", &l);
}

static void test_str_pointer(t_test *test)
{
	char *str;

	// test->debug = 1;
	assert_printf("%p", &str);
}

static void test_function_pointer(t_test *test)
{
	// test->debug = 1;
	assert_printf("%p", &strlen);
}

static void test_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%p", 0);
}

void	suite_04_conv_p(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_int_pointer);
	SUITE_ADD_TEST(suite, test_unsigned_long_pointer);
	SUITE_ADD_TEST(suite, test_str_pointer);
	SUITE_ADD_TEST(suite, test_function_pointer);
	SUITE_ADD_TEST(suite, test_zero);
}

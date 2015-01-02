#include <project.h>
#include <limits.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%D", 0L);
	assert_printf("%D", 1L);
	assert_printf("%D", -1L);
	assert_printf("%D", 42L);
}

static void test_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%D", LONG_MAX);
}

static void test_long_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%D", LONG_MIN);
}

static void test_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("Coucou les %D!", 42);
}

void	suite_08_conv_D(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_long_max);
	SUITE_ADD_TEST(suite, test_long_min);
	SUITE_ADD_TEST(suite, test_with_strings);
}

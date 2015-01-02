#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_space_d_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("% d", 9999);
}

static void test_space_d_simple_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("% d", -9999);
}

static void test_space_i_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("% i", 9999);
}

static void test_space_i_simple_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("% i", -9999);
}

static void test_space_c_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% c}", 0);
}

void	suite_62_flag_space(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_space_d_simple);
	SUITE_ADD_TEST(suite, test_space_d_simple_minus);
	SUITE_ADD_TEST(suite, test_space_i_simple);
	SUITE_ADD_TEST(suite, test_space_i_simple_minus);
	SUITE_ADD_TEST(suite, test_space_c_zero);
}

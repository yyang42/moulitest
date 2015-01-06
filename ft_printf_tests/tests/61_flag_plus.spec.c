#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_plus_d_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+d", 42);
}

static void test_plus_d_simple_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+d", -42);
}

static void test_plus_i_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+i", 42);
}

static void test_plus_i_simple_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+i", -42);
}

static void test_plus_c_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+c", 0);
}

static void test_plus_c_up_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+C", 0);
}

static void test_plus_o_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+o", 0);
}

static void test_plus_o_42(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+o", 42);
}

static void test_plus_o_up_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+O", 0);
}

static void test_plus_o_up_42(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+O", 42);
}

static void sNullString_plusFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("[%+s]", 0);
}

static void sFakeNullString_plusFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("[%+s]", "(null)");
}

static void octalUppercase(t_test *test)
{
	// test->debug = 1;
	assert_printf("%+O", 1);
}

void	suite_61_flag_plus(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_plus_d_simple);
	SUITE_ADD_TEST(suite, test_plus_d_simple_minus);
	SUITE_ADD_TEST(suite, test_plus_i_simple);
	SUITE_ADD_TEST(suite, test_plus_i_simple_minus);
	SUITE_ADD_TEST(suite, test_plus_c_zero);
	SUITE_ADD_TEST(suite, test_plus_c_up_zero);
	SUITE_ADD_TEST(suite, test_plus_o_zero);
	SUITE_ADD_TEST(suite, test_plus_o_42);
	SUITE_ADD_TEST(suite, test_plus_o_up_zero);
	SUITE_ADD_TEST(suite, test_plus_o_up_42);
	SUITE_ADD_TEST(suite, sNullString_plusFlag);
	SUITE_ADD_TEST(suite, sFakeNullString_plusFlag);
	SUITE_ADD_TEST(suite, octalUppercase);
}

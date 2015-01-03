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

static void cValidChar_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% c}", 'a');
}

static void sNullString_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% s}", NULL);
}

static void sFakeNullString_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% s}", "(null)");
}

void	suite_62_flag_space(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_space_d_simple);
	SUITE_ADD_TEST(suite, test_space_d_simple_minus);
	SUITE_ADD_TEST(suite, test_space_i_simple);
	SUITE_ADD_TEST(suite, test_space_i_simple_minus);
	SUITE_ADD_TEST(suite, test_space_c_zero);
	SUITE_ADD_TEST(suite, cValidChar_spaceFlag);
	SUITE_ADD_TEST(suite, sNullString_spaceFlag);
	SUITE_ADD_TEST(suite, sFakeNullString_spaceFlag);
}

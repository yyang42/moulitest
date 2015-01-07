#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_zd_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zd%zd", 0, 42);
}

static void test_zd_llong_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zd", LLONG_MAX);
}

static void test_zi_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zi%zi", 0, 42);
}

static void test_zi_llong_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zi", LLONG_MAX);
}

static void test_zu_unsign_long_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zu, %zu", 0, ULLONG_MAX);
}

static void test_zo_unsign_long_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zo, %zo", 0, ULLONG_MAX);
}

static void test_zx_unsign_long_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zx, %zx", 0, ULLONG_MAX);
}

static void test_zX_unsign_long_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zX, %zX", 0, ULLONG_MAX);
}

static void test_err_zo_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zO, %zO", 0, USHRT_MAX);
}

static void test_err_zu_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zU, %zU", 0, USHRT_MAX);
}
static void test_err_zd_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%zD, %zD", 0, USHRT_MAX);
}

void	suite_44_length_modif_z(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_zd_simple);
	SUITE_ADD_TEST(suite, test_zd_llong_max);

	SUITE_ADD_TEST(suite, test_zi_simple);
	SUITE_ADD_TEST(suite, test_zi_llong_max);

	SUITE_ADD_TEST(suite, test_zu_unsign_long_long_max);
	SUITE_ADD_TEST(suite, test_zo_unsign_long_long_max);
	SUITE_ADD_TEST(suite, test_zx_unsign_long_long_max);
	SUITE_ADD_TEST(suite, test_zX_unsign_long_long_max);

	SUITE_ADD_TEST(suite, test_err_zo_up_max);
	SUITE_ADD_TEST(suite, test_err_zu_up_max);
	SUITE_ADD_TEST(suite, test_err_zd_up_max);
}

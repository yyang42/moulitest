#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_ld_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%ld%ld", 0, 42);
}

static void test_ld_int_max_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%ld", (long)INT_MAX + 1);
}

static void test_ld_int_min_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%ld", (long)INT_MIN - 1);
}

static void test_ld_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%ld", LONG_MAX);
}

static void test_ld_long_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%ld", LONG_MIN);
}

static void test_li_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%li%li", 0, 42);
}

static void test_li_int_max_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%li", (long)INT_MAX + 1);
}

static void test_li_int_min_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%li", (long)INT_MIN - 1);
}

static void test_li_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%li", LONG_MAX);
}

static void test_li_long_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%li", LONG_MIN);
}

static void test_lu_long_unsigned_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lu, %lu", 0, ULONG_MAX);
}

static void test_lo_long_unsigned_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lo, %lo", 0, ULONG_MAX);
}

static void test_lx_long_unsigned_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lx, %lx", 0, ULONG_MAX);
}

static void test_lX_long_unsigned_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lX, %lX", 0, ULONG_MAX);
}

static void test_lc_wchar(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lc, %lc", L'暖', L'ح');
}

static void test_ls_wchar(t_test *test)
{
	// test->debug = 1;
	assert_printf("%ls, %ls", L"暖炉", L"لحم خنزير");
}

static void test_err_lo_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lO, %lO", 0, USHRT_MAX);
}

static void test_err_lu_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lU, %lU", 0, USHRT_MAX);
}
static void test_err_ld_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lD, %lD", 0, USHRT_MAX);
}

void	suite_40_length_modif_l(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_ld_simple);
	SUITE_ADD_TEST(suite, test_ld_int_max_plus);
	SUITE_ADD_TEST(suite, test_ld_int_min_minus);
	SUITE_ADD_TEST(suite, test_ld_long_max);
	SUITE_ADD_TEST(suite, test_ld_long_min);

	SUITE_ADD_TEST(suite, test_li_simple);
	SUITE_ADD_TEST(suite, test_li_int_max_plus);
	SUITE_ADD_TEST(suite, test_li_int_min_minus);
	SUITE_ADD_TEST(suite, test_li_long_max);
	SUITE_ADD_TEST(suite, test_li_long_min);

	SUITE_ADD_TEST(suite, test_lu_long_unsigned_max);
	SUITE_ADD_TEST(suite, test_lo_long_unsigned_max);
	SUITE_ADD_TEST(suite, test_lx_long_unsigned_max);
	SUITE_ADD_TEST(suite, test_lX_long_unsigned_max);
	SUITE_ADD_TEST(suite, test_lc_wchar);
	SUITE_ADD_TEST(suite, test_ls_wchar);

	SUITE_ADD_TEST(suite, test_err_lo_up_max);
	SUITE_ADD_TEST(suite, test_err_lu_up_max);
	SUITE_ADD_TEST(suite, test_err_ld_up_max);
}

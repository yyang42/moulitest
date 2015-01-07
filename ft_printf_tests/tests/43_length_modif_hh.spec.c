#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_hhd_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhd%hhd", 1, 42);
}

static void test_hhd_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhd", CHAR_MAX);
}

static void test_hhd_max_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhd", CHAR_MAX + 42);
}

static void test_hhd_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhd", CHAR_MIN);
}

static void test_hhd_min_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhd", CHAR_MIN - 42);
}

static void test_hhi_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhi%hhi", 0, 42);
}

static void test_hhi_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhd", CHAR_MAX);
}

static void test_hhi_max_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhd", CHAR_MAX + 42);
}

static void test_hhi_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhi", CHAR_MIN);
}

static void test_hhi_min_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhi", CHAR_MIN - 42);
}

static void test_hhu_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhu, %hhu", 0, UCHAR_MAX);
}

static void test_hho_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hho, %hho", 0, UCHAR_MAX);
}

static void test_hhx_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhx, %hhx", 0, UCHAR_MAX);
}

static void test_hhX_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhX, %hhX", 0, UCHAR_MAX);
}

static void test_hhu_max_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhu, %hhu", 0, UCHAR_MAX + 42);
}

static void test_hho_max_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hho, %hho", 0, UCHAR_MAX + 42);
}

static void test_hhx_max_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhx, %hhx", 0, UCHAR_MAX + 42);
}

static void test_hhX_max_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhX, %hhX", 0, UCHAR_MAX + 42);
}

static void test_err_hho_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhO, %hhO", 0, USHRT_MAX);
}

static void test_err_hhu_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhU, %hhU", 0, USHRT_MAX);
}

static void test_err_hhd_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhD, %hhD", 0, USHRT_MAX);
}

static void test_err_hhc_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhC, %hhC", 0, L'米');
}

static void test_err_hhs_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhS, %hhS", 0, L"米米");
}

void	suite_43_length_modif_hh(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_hhd_simple);
	SUITE_ADD_TEST(suite, test_hhd_max);
	SUITE_ADD_TEST(suite, test_hhd_max_plus);
	SUITE_ADD_TEST(suite, test_hhd_min);
	SUITE_ADD_TEST(suite, test_hhd_min_minus);

	SUITE_ADD_TEST(suite, test_hhi_simple);
	SUITE_ADD_TEST(suite, test_hhi_max);
	SUITE_ADD_TEST(suite, test_hhi_max_plus);
	SUITE_ADD_TEST(suite, test_hhi_min);
	SUITE_ADD_TEST(suite, test_hhi_min_minus);

	SUITE_ADD_TEST(suite, test_hhu_max);
	SUITE_ADD_TEST(suite, test_hho_max);
	SUITE_ADD_TEST(suite, test_hhx_max);
	SUITE_ADD_TEST(suite, test_hhX_max);
	SUITE_ADD_TEST(suite, test_hhu_max_plus);
	SUITE_ADD_TEST(suite, test_hho_max_plus);
	SUITE_ADD_TEST(suite, test_hhx_max_plus);
	SUITE_ADD_TEST(suite, test_hhX_max_plus);

	SUITE_ADD_TEST(suite, test_err_hho_up_max);
	SUITE_ADD_TEST(suite, test_err_hhu_up_max);
	SUITE_ADD_TEST(suite, test_err_hhd_up_max);
	SUITE_ADD_TEST(suite, test_err_hhc_up_max);
	SUITE_ADD_TEST(suite, test_err_hhs_up_max);
}

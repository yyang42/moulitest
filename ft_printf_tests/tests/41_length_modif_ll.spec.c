#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_lld_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lld%lld", 0, 42);
}

static void test_lld_llong_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lld", LLONG_MAX);
}

static void test_lld_llong_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lld", LLONG_MIN);
}

static void test_lli_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lli%lli", 0, 42);
}

static void test_lli_llong_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lli", LLONG_MAX);
}

static void test_lli_llong_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lli", LLONG_MIN);
}

static void test_llu_unsign_long_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%llu, %llu", 0, ULLONG_MAX);
}

static void test_llo_unsign_long_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%llo, %llo", 0, ULLONG_MAX);
}

static void test_llx_unsign_long_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%llx, %llx", 0, ULLONG_MAX);
}

static void test_llX_unsign_long_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%llX, %llX", 0, ULLONG_MAX);
}

static void test_err_llo_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%llO, %llO", 0, USHRT_MAX);
}

static void test_err_llu_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%llU, %llU", 0, USHRT_MAX);
}
static void test_err_lld_up_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%llD, %llD", 0, USHRT_MAX);
}

void	suite_41_length_modif_ll(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_lld_simple);
	SUITE_ADD_TEST(suite, test_lld_llong_max);
	SUITE_ADD_TEST(suite, test_lld_llong_min);

	SUITE_ADD_TEST(suite, test_lli_simple);
	SUITE_ADD_TEST(suite, test_lli_llong_max);
	SUITE_ADD_TEST(suite, test_lli_llong_min);

	SUITE_ADD_TEST(suite, test_llu_unsign_long_long_max);
	SUITE_ADD_TEST(suite, test_llo_unsign_long_long_max);
	SUITE_ADD_TEST(suite, test_llx_unsign_long_long_max);
	SUITE_ADD_TEST(suite, test_llX_unsign_long_long_max);

	SUITE_ADD_TEST(suite, test_err_llo_up_max);
	SUITE_ADD_TEST(suite, test_err_llu_up_max);
	SUITE_ADD_TEST(suite, test_err_lld_up_max);
}

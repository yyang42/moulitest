#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_ld_simple(t_test *test)
{
	// debug_next_assert();
	assert_printf("%ld%ld", 0, 42);
}

static void test_ld_int_max_plus(t_test *test)
{
	// debug_next_assert();
	assert_printf("%ld", (long)INT_MAX + 1);
}

static void test_ld_int_min_minus(t_test *test)
{
	// debug_next_assert();
	assert_printf("%ld", (long)INT_MIN - 1);
}

static void test_ld_long_max(t_test *test)
{
	// debug_next_assert();
	assert_printf("%ld", LONG_MAX);
}

static void test_ld_long_min(t_test *test)
{
	// debug_next_assert();
	assert_printf("%ld", LONG_MIN);
}

static void test_li_simple(t_test *test)
{
	// debug_next_assert();
	assert_printf("%li%li", 0, 42);
}

static void test_li_int_max_plus(t_test *test)
{
	// debug_next_assert();
	assert_printf("%li", (long)INT_MAX + 1);
}

static void test_li_int_min_minus(t_test *test)
{
	// debug_next_assert();
	assert_printf("%li", (long)INT_MIN - 1);
}

static void test_li_long_max(t_test *test)
{
	// debug_next_assert();
	assert_printf("%li", LONG_MAX);
}

static void test_li_long_min(t_test *test)
{
	// debug_next_assert();
	assert_printf("%li", LONG_MIN);
}

static void test_lu_long_unsigned_max(t_test *test)
{
	// debug_next_assert();
	assert_printf("%lu, %lu", 0, ULONG_MAX);
}

void	suite_19_length_modif_h(t_suite *suite)
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
}

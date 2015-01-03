#include <project.h>
#include <limits.h>

static void test_unsigned_neg(t_test *test)
{
	// test->debug = 1;
	assert_printf("%u", -42);
}

static void test_unsigned_max_plus_one(t_test *test)
{
	// test->debug = 1;
	assert_printf("%u", UINT_MAX + 1);
}

static void test_unsigned_long_max_plus_one(t_test *test)
{
	// test->debug = 1;
	assert_printf("%U", ULONG_MAX + 1);
}

static void test_big_char(t_test *test)
{
	// test->debug = 1;
	assert_printf("%c", 200);
}

static void test_u_incompatible_flags(t_test *test)
{
	// test->debug = 1;
	assert_printf("% u|%+u", 42, 42);
}

static void test_hhu(t_test *test)
{
	// test->debug = 1;
	assert_printf("%hhu / %hhu", SHRT_MAX - 42,  SHRT_MAX - 4200);
}


void	suite_91_incomptbl_values_uUSDcC(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_unsigned_neg);
	SUITE_ADD_TEST(suite, test_unsigned_max_plus_one);
	SUITE_ADD_TEST(suite, test_unsigned_long_max_plus_one);
	SUITE_ADD_TEST(suite, test_big_char);
	SUITE_ADD_TEST(suite, test_u_incompatible_flags);
	SUITE_ADD_TEST(suite, test_hhu);
}

#include <project.h>
#include <limits.h>

static void test_octal_neg(t_test *test)
{
	// debug_next_assert();
	assert_printf("%o, %ho, %hho", -42, -42, -42);
}

static void test_octal_long_max(t_test *test)
{
	// debug_next_assert();
	assert_printf("%o", LONG_MAX);
}

static void test_octal_up_long_min(t_test *test)
{
	// debug_next_assert();
	assert_printf("%O", LONG_MIN);
}

static void test_unsigned_neg(t_test *test)
{
	// debug_next_assert();
	assert_printf("%u", -42);
}

static void test_unsigned_max_plus_one(t_test *test)
{
	// debug_next_assert();
	assert_printf("%u", UINT_MAX + 1);
}

static void test_unsigned_long_max_plus_one(t_test *test)
{
	// debug_next_assert();
	assert_printf("%U", ULONG_MAX + 1);
}

static void test_big_char(t_test *test)
{
	// debug_next_assert();
	assert_printf("%c", 200);
}

static void test_hhd(t_test *test)
{
	// debug_next_assert();
	assert_printf("%hhd - %hhd", SHRT_MAX - 42,  SHRT_MAX - 4200);
}

static void test_zi(t_test *test)
{
	// debug_next_assert();
	assert_printf("%zi", LLONG_MIN);
}

static void test_zd(t_test *test)
{
	// debug_next_assert();
	assert_printf("%zd", LLONG_MIN);
}

static void test_o_incompatible_flags(t_test *test)
{
	// debug_next_assert();
	assert_printf("% o|%+o", 42, 42);
}

static void test_x_incompatible_flags(t_test *test)
{
	// debug_next_assert();
	assert_printf("% x|%+x", 42, 42);
}

static void test_x_up_incompatible_flags(t_test *test)
{
	// debug_next_assert();
	assert_printf("% X|%+X", 42, 42);
}

static void test_p_incompatible_flags(t_test *test)
{
	// debug_next_assert();
	assert_printf("% p|%+p", 42, 42);
}

static void test_u_incompatible_flags(t_test *test)
{
	// debug_next_assert();
	assert_printf("% u|%+u", 42, 42);
}


void	suite_20_forbidden_value(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_octal_neg);
	SUITE_ADD_TEST(suite, test_octal_long_max);
	SUITE_ADD_TEST(suite, test_octal_up_long_min);
	SUITE_ADD_TEST(suite, test_unsigned_neg);
	SUITE_ADD_TEST(suite, test_unsigned_max_plus_one);
	SUITE_ADD_TEST(suite, test_unsigned_long_max_plus_one);
	SUITE_ADD_TEST(suite, test_big_char);
	SUITE_ADD_TEST(suite, test_hhd);
	SUITE_ADD_TEST(suite, test_zi);
	SUITE_ADD_TEST(suite, test_zd);
	SUITE_ADD_TEST(suite, test_o_incompatible_flags);
	SUITE_ADD_TEST(suite, test_x_incompatible_flags);
	SUITE_ADD_TEST(suite, test_x_up_incompatible_flags);
	SUITE_ADD_TEST(suite, test_p_incompatible_flags);
	SUITE_ADD_TEST(suite, test_u_incompatible_flags);
}

/*


	assert_printf("%#.o", 42);
	assert_printf("%#+12.45llp", 42645454564);*/
#include <project.h>
#include <limits.h>

static void test_octal_neg(t_test *test)
{
	// test->debug = 1;
	assert_printf("%o, %ho, %hho", -42, -42, -42);
}

static void test_octal_long_max(t_test *test)
{
	// test->debug = 1;
	assert_printf("%o", LONG_MAX);
}

/*
//Disabling this test because it is no longer mandatory
static void test_octal_up_long_min(t_test *test)
{
	// test->debug = 1;
	assert_printf("%O", LONG_MIN);
}

//Disabling this test because -Wformat says undefined behavior
static void test_octal_space_plus(t_test *test)
{
	// test->debug = 1;
	assert_printf("% o|%+o", 42, 42);
}
*/

static void test_octal_sharp_precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%#.o", 42);
}

/*
//Disabling this test because -Wformat says undefined behavior
static void test_x_incompatible_flags(t_test *test)
{
	// test->debug = 1;
	assert_printf("% x|%+x", 42, 42);
}
//Disabling this test because -Wformat says undefined behavior
static void test_x_up_incompatible_flags(t_test *test)
{
	// test->debug = 1;
	assert_printf("% X|%+X", 42, 42);
}
*/

void	suite_92_incomptbl_values_oOxX(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_octal_neg);
	SUITE_ADD_TEST(suite, test_octal_long_max);
	//SUITE_ADD_TEST(suite, test_octal_up_long_min);
	//SUITE_ADD_TEST(suite, test_octal_space_plus);
	SUITE_ADD_TEST(suite, test_octal_sharp_precision);
	//SUITE_ADD_TEST(suite, test_x_incompatible_flags);
	//SUITE_ADD_TEST(suite, test_x_up_incompatible_flags);
}

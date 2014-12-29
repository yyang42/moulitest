#include <project.h>

static void test_simple(t_test *test)
{
	debug_next_assert();
	assert_printf("%X", 42);
}

static void test_hex_with_strings(t_test *test)
{
	// debug_next_assert();
	assert_printf("before %X after", 42);
}

static void test_many_hexs(t_test *test)
{
	// debug_next_assert();
	assert_printf("%X%X%X%X%X",
		1, 100, 999, 42, 999988888);
}

static void test_many_hexs_with_strings(t_test *test)
{
	// debug_next_assert();
	assert_printf("a%Xb%Xc%Xd",
		0, 55555, 100000);
}

void	suite_15_conv_X(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_hex_with_strings);
	SUITE_ADD_TEST(suite, test_many_hexs);
	SUITE_ADD_TEST(suite, test_many_hexs_with_strings);
}

#include <project.h>

static void test_simple(t_test *test)
{
	// debug_on();
	// assert_printf("%S", L"米");
	assert(0);
	// debug_off();
}

void	suite_07_conv_S(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}

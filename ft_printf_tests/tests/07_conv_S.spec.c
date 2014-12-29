#include <project.h>

static void test_simple(t_test *test)
{
	debug_next_assert();
	assert_printf("%S", L"米");
}

void	suite_07_conv_S(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}

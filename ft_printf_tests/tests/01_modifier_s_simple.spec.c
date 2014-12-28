#include <project.h>

static void simple_convertion_s(t_test *test)
{
	// debug_on();
	assert_printf("111%s333", "222");
	// debug_off();
}

void	suite_01_modifier_s_simple(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_convertion_s);
}

#include <project.h>

static void simple_convertion_s(t_test *test)
{
	// debug_on();
	assert_printf("Hello %s.", "world");
	// debug_off();
}

void	suite_04_simple_string(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_convertion_s);
}

#include <project.h>

static void test_int_pointer(t_test *test)
{
	debug_on();
	int i;

	i = 5;
	assert_printf("%p", &i);
	debug_off();
}


void	suite_04_modifier_p(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_int_pointer);
}

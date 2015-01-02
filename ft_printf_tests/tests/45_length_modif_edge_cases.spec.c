#include <project.h>
#include <limits.h>
#include <signal.h>

static void ignore_length_modifiers_with_p_conv(t_test *test)
{
	// test->debug = 1;
	assert_printf("%lp", 42);
}

void	suite_45_length_modif_edge_cases(t_suite *suite)
{
	SUITE_ADD_TEST(suite, ignore_length_modifiers_with_p_conv);
}

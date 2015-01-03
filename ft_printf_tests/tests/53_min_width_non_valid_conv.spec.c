#include <project.h>
#include <limits.h>
#include <signal.h>

static void nonValidConv_negativeMinWidth(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%-15Z}", 123);
}

void	suite_53_min_width_non_valid_conv(t_suite *suite)
{
	SUITE_ADD_TEST(suite, nonValidConv_negativeMinWidth);
}

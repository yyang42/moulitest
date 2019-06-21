#include <project.h>
#include <limits.h>
#include <signal.h>

//Disabling this test because it has no defined behavior in printf(3)
static void percent_point3precision(t_test *test)
{
	// test->debug = 1;
	assert_printf("%.3%");
}

void	suite_75_precision_for_percent(t_suite *suite)
{
	//SUITE_ADD_TEST(suite, percent_point3precision);
}

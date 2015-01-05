#include <project.h>
#include <limits.h>
#include <signal.h>

static void test(t_test *test)
{
	// test->debug = 1;
	assert_printf("Bla bla %03*.d", 10, -123);
}

void	suite_sandbox(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test);
}

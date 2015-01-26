#include <project.h>

static void simple_exit_test(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test, "exit\n", "grep exit");
}

void	suite_0_sh1_00_cmd_exit(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_exit_test);
}

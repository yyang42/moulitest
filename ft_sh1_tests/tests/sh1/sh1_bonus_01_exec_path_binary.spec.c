#include <project.h>

static void simple(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"cd "SANDBOX_PATH"\n"
		"touch file\n"
		"cd ..\n"
		"setenv PATH "SANDBOX_PATH"\n"
		"file\n"
		"exit\n");
}

void	suite_sh1_bonus_01_exec_path_binary(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
}

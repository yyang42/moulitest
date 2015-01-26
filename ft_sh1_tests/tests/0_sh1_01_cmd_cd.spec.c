#include <project.h>

static void cd_to_home(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,  "cd\npwd\nexit\n",
						"grep `whoami`$");
}

static void cd_to_path_simple(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,  "cd /usr\n"
						"pwd\n"
						"exit\n", "grep /usr");
}

static void cd_should_ignore_extra_args(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,  "cd /usr arg2\n"
						"pwd\n"
						"exit\n", "grep /usr");
}

void	suite_0_sh1_01_cmd_cd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, cd_to_home);
	SUITE_ADD_TEST(suite, cd_to_path_simple);
	SUITE_ADD_TEST(suite, cd_should_ignore_extra_args);
}

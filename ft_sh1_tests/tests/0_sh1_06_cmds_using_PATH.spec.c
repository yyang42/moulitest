#include <project.h>

static void test_ls_cmd(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"ls /\n"
		"exit\n",
		"tr '\n' ' ' | grep 'Applications.*Users.*Volumes.*var'");
}

static void test_whoami_cmd(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"whoami\n"
		"exit\n",
		"grep ''");
}

static void test_echo_cmd(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo 'MOULITEST'\n"
		"exit\n",
		"grep 'MOULITEST'");
}

void	suite_0_sh1_06_cmds_using_PATH(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_ls_cmd);
	SUITE_ADD_TEST(suite, test_whoami_cmd);
	SUITE_ADD_TEST(suite, test_echo_cmd);
}

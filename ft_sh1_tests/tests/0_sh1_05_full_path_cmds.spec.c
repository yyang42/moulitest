#include <project.h>

static void simple_test(t_test *test)
{
	test->debug = 1;
	mt_assert_sh_stdout(test,
		"/bin/ls /\n"
		"exit\n",
		"tr '\n' ' ' | grep 'Applications.*Users.*Volumes.*var'");
}

static void simple_test_wc(t_test *test)
{
	test->debug = 1;
	mt_assert_sh_stdout(test,
		"/usr/bin/whoami\n"
		"exit\n",
		"grep ''");
}

void	suite_0_sh1_05_full_path_cmds(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test_wc);
}

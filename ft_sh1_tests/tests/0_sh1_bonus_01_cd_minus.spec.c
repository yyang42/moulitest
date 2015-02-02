#include <project.h>

static void simple_test(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"cd\n"
		"cd /\n"
		"cd -\n"
		"pwd\n"
		"exit\n",
		"grep `whoami`$");
}

static void OLDPWD_not_exist(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"unsetenv OLDPWD\n"
		"cd -\n"
		"exit\n");
}

static void HOME_not_exist(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"unsetenv HOME\n"
		"cd\n"
		"exit\n");
}

void	suite_0_sh1_bonus_01_cd_minus(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, OLDPWD_not_exist);
	SUITE_ADD_TEST(suite, HOME_not_exist);
}

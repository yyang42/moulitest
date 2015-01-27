#include <project.h>

static void simple_semi_colon_test(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo cerisier; echo hector; ls /\n"
		"exit\n",
		"tr '\n' ' ' | grep 'cerisier.*hector.*Applications'");
}

static void test_semi_colon_with_errors(t_test *test)
{
	test->debug = 1;
	char cmd[] = "echo cerisier; notexistingcmd\nexit\n";

	mt_assert_sh_stdout(test, cmd,
		"tr '\n' ' ' | grep 'cerisier'");
	mt_assert_sh_stderr_not_empty(test, cmd);
}

void	suite_0_sh1_bonus_00_semi_colon(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_semi_colon_test);
	SUITE_ADD_TEST(suite, test_semi_colon_with_errors);
}

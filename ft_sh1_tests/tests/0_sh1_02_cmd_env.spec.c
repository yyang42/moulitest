#include <project.h>

static void assert_home_exist(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test, "env\nexit\n", "grep '^HOME='");
}

static void assert_path_exist(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test, "env\n" "exit\n", "grep '^PATH='");
}

static void assert_term_exist(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test, "env\n" "exit\n", "grep '^TERM='");
}

static void test_too_many_args(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test, "env invalid_arg\n" "exit\n");
}

void	suite_0_sh1_02_cmd_env(t_suite *suite)
{
	SUITE_ADD_TEST(suite, assert_home_exist);
	SUITE_ADD_TEST(suite, assert_path_exist);
	SUITE_ADD_TEST(suite, assert_term_exist);
	SUITE_ADD_TEST(suite, test_too_many_args);
}

#include <project.h>

static void test_opt_i(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test, "env -i a=b env\nexit\n", "grep '^a=b'");
}

static void test_opt_i_test_with_sh(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout_not_contains(test,
		"setenv a b\n"
		"env -i sh\n"
		"env\n"
		"exit\n"
		"exit\n",
		"grep '^a=b'");
}

void	suite_sh1_extra_00_cmd_env(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_opt_i);
	SUITE_ADD_TEST(suite, test_opt_i_test_with_sh);
}

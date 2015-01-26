#include <project.h>

static void simple_unsetenv_test(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout_not_contains(test,
		"setenv aaa 111\nunsetenv aaa\nenv\nexit\n",
		"grep '^aaa='");
}

static void test_not_existing_key(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_is_empty(test, "unsetenv keydoesnotexist\nexit\n");
}

static void unset_multiple_envs(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout_not_contains(test,
		"setenv MTENV_A\nsetenv MTENV_B\nsetenv MTENV_C\nunsetenv MTENV_A MTENV_B MTENV_C\nenv\nexit\n",
		"grep 'MTENV_A\\|MTENV_B\\|MTENV_C'");
}

void	suite_0_sh1_04_cmd_unsetenv(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_unsetenv_test);
	SUITE_ADD_TEST(suite, test_not_existing_key);
	SUITE_ADD_TEST(suite, unset_multiple_envs);
}

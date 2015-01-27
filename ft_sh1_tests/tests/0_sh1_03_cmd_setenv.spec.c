#include <project.h>

static void simple_setenv_test(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test, "setenv aaa 111\nenv\nexit\n", "grep '^aaa=111$'");
}

static void simple_setenv_empty(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test, "setenv bbb\nenv\nexit\n", "grep '^bbb=$'");
}

static void simple_setenv_too_many_args(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test, "setenv aaa bbb ccc\nenv\nexit\n");
}

static void simple_setenv_no_arg(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test, "setenv\nexit\n", "grep '^HOME='");
}

static void does_it_really_modified_envs(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test, "setenv MTENV\n/usr/bin/env\nexit\n", "grep '^MTENV='");
}

void	suite_0_sh1_03_cmd_setenv(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_setenv_test);
	SUITE_ADD_TEST(suite, simple_setenv_empty);
	SUITE_ADD_TEST(suite, simple_setenv_too_many_args);
	SUITE_ADD_TEST(suite, simple_setenv_no_arg);
	SUITE_ADD_TEST(suite, does_it_really_modified_envs);
}

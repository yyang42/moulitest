#include <project.h>

static void cmd_does_not_exist(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"thisCommandDoesNotExist\n"
		"exit\n");
}

static void cmd_exist_but_not_in_path(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"unsetenv PATH\nls\n"
		"exit\n");
}

static void handle_tabs_spaces(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		" \t\t\t    echo 'moulitest'  \t\t\t   \t\n"
		"exit\n",
		"grep 'moulitest'");
}

void	suite_0_sh1_20_error_handling(t_suite *suite)
{
	SUITE_ADD_TEST(suite, cmd_does_not_exist);
	SUITE_ADD_TEST(suite, cmd_exist_but_not_in_path);
	SUITE_ADD_TEST(suite, handle_tabs_spaces);
}

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

static void empty_line_should_not_send_err(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_is_empty(test,
		"\n"
		"exit\n");
}

static void empty_line_with_blank_chars(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_is_empty(test,
		" \t\t\t    \n"
		"exit\n");
}

void	suite_0_sh1_20_error_handling(t_suite *suite)
{
	SUITE_ADD_TEST(suite, cmd_does_not_exist);
	SUITE_ADD_TEST(suite, cmd_exist_but_not_in_path);
	SUITE_ADD_TEST(suite, handle_tabs_spaces);
	SUITE_ADD_TEST(suite, empty_line_should_not_send_err);
	SUITE_ADD_TEST(suite, empty_line_with_blank_chars);
}

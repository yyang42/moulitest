#include <project.h>

static void mix_stdout_stdin(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo abc > "SANDBOX_PATH"/file ; cat < "SANDBOX_PATH"/file > "SANDBOX_PATH"/output\n"
		"exit\n"
		,
		"&> /dev/null; cat "SANDBOX_PATH"/output | grep abc");
}

static void mix_stdout_append(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo aaa > "SANDBOX_PATH"/file\n"
		"echo bbb >> "SANDBOX_PATH"/file\n"
		"exit\n"
		,
		"&> /dev/null; cat "SANDBOX_PATH"/file | tr -d '\n' | grep aaabbb");
}

static void mix_stdout_append_stdin(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo aaa > "SANDBOX_PATH"/file\n"
		"echo bbb >> "SANDBOX_PATH"/file\n"
		"cat < "SANDBOX_PATH"/file > "SANDBOX_PATH"/output\n"
		"exit\n"
		,
		"&> /dev/null; cat "SANDBOX_PATH"/output | tr -d '\n' | grep aaabbb");
}

void	suite_sh2_20_redir_mix(t_suite *suite)
{
	SUITE_ADD_TEST(suite, mix_stdout_stdin);
	SUITE_ADD_TEST(suite, mix_stdout_append);
	SUITE_ADD_TEST(suite, mix_stdout_append_stdin);
}

#include <project.h>

static void test_redir_stdout(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo abc>"SANDBOX_PATH"/file ; cat < "SANDBOX_PATH"/file > "SANDBOX_PATH"/output\n"
		"exit\n"
		,
		"&> /dev/null; cat "SANDBOX_PATH"/output | grep abc");
}

static void test_redir_append(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo 84>>"SANDBOX_PATH"/file\n"
		"echo 21>>"SANDBOX_PATH"/file\n"
		"exit\n"
		,
		"&> /dev/null; cat "SANDBOX_PATH"/file | tr -d '\n' | grep 8421");
}

static void test_redir_stdin(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo abc>file ; cat<file\n"
		"exit\n"
		,
		"grep abc");
}

static void test_redir_heredoc(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"cat<<EOF\nexit\naa\nbb\ncc\nEOF\nexit\n"
		,
		"tr -d '\n' | grep aabbcc");
}

void	suite_sh2_21_redir_parsing(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_redir_stdout);
	SUITE_ADD_TEST(suite, test_redir_append);
	SUITE_ADD_TEST(suite, test_redir_stdin);
	SUITE_ADD_TEST(suite, test_redir_heredoc);
}

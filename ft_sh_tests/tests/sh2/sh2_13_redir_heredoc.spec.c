#include <project.h>

static void test_redir_heredoc(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"cat << EOF\nexit\naa\nbb\ncc\nEOF\nexit\n"
		,
		"tr -d '\n' | grep aabbcc");
}

void	suite_sh2_13_redir_heredoc(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_redir_heredoc);
}

#include <project.h>

static void test_redir_stdin(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo abc > file ; cat < file\n"
		"exit\n"
		,
		"grep abc");
}

void	suite_sh2_12_redir_stdin(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_redir_stdin);
}

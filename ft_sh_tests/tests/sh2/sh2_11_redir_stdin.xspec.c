#include <project.h>

static void test_redir_stdin(t_test *test)
{
	test->debug = 1;
	mt_assert_sh_stdout(test,
		"cat < 424242\nexit\n"
		,
		"grep 424242");
}

void	suite_sh2_11_redir_stdin(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_redir_stdin);
}

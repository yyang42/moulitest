#include <project.h>

static void test_redir_stdout(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo 424242 > "SANDBOX_PATH"/file\nexit\n"
		,
		"&> /dev/null; grep 424242 "SANDBOX_PATH"/file");
}

static void test_redir_stdout_with_ls(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"ls / > "SANDBOX_PATH"/file\nexit\n"
		,
		"&> /dev/null; grep bin "SANDBOX_PATH"/file");
}

void	suite_sh2_10_redir_stdout(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_redir_stdout);
	SUITE_ADD_TEST(suite, test_redir_stdout_with_ls);
}

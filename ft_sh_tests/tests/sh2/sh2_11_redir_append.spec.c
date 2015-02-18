#include <project.h>

static void test_redir_append(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo 84 >> "SANDBOX_PATH"/file\n"
		"echo 21 >> "SANDBOX_PATH"/file\n"
		"exit\n"
		,
		"&> /dev/null; cat "SANDBOX_PATH"/file | tr -d '\n' | grep 8421");
}

void	suite_sh2_11_redir_append(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_redir_append);
}

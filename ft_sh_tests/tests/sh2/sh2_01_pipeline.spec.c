#include <project.h>

static void test_one_pipe(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo abc | cat -e\n"
		,
		"grep 'abc\\$'");
}

static void test_more_pipes(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"echo 000/bin000 | tr -d 0 | xargs ls\n"
		,
		"grep cat");
}

void	suite_sh2_01_pipeline(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_one_pipe);
	SUITE_ADD_TEST(suite, test_more_pipes);
}

#include <project.h>

static void test1(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"cat <>\n"
		"exit\n");
}

static void test2(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"cat <\n"
		"exit\n");
}

static void test3(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"cat >\n"
		"exit\n");
}

static void test4(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"cat >>\n"
		"exit\n");
}

static void test5(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"cat <<\n"
		"exit\n");
}

static void test6(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"cat <<>>>>>>>>><<<<<>>>> file\n"
		"exit\n");
}

static void test7(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stderr_not_empty(test,
		"cat > file < file <> file\n"
		"exit\n");
}

void	suite_sh2_30_redir_error_handling(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
	SUITE_ADD_TEST(suite, test4);
	SUITE_ADD_TEST(suite, test5);
	SUITE_ADD_TEST(suite, test6);
	SUITE_ADD_TEST(suite, test7);
}

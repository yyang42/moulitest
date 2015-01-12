#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd;

	reset_sandbox();
	cmd = "-1 mydir mydir2";
	sandbox_cmd("mkdir mydir mydir2 && touch mydir/{aaa,bbb,ccc} && touch mydir2/{111,222,333}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
	char *cmd;

	reset_sandbox();
	cmd = "-1 mydir mydir2";
	sandbox_cmd("mkdir mydir mydir2 && touch mydir/file{10..20} && touch mydir2/file{30..40}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_2(t_test *test)
{
	char *cmd;

	reset_sandbox();
	cmd = "-1 mydir{1..7}";
	sandbox_cmd("mkdir mydir{1..7} && touch mydir{1..7}/file{1..11}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_3(t_test *test)
{
	char *cmd;

	reset_sandbox();
	cmd = "-1 mydir";
	sandbox_cmd("mkdir mydir && touch mydir/a");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_4(t_test *test)
{
	char *cmd;

	reset_sandbox();
	cmd = "-1 ./mydir";
	sandbox_cmd("mkdir ./mydir && touch ./mydir/{a,b,c}");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_03_test_multiple_dir(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);
	SUITE_ADD_TEST(suite, simple_test_2);
	SUITE_ADD_TEST(suite, simple_test_3);
	SUITE_ADD_TEST(suite, simple_test_4);


}
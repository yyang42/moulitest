#include <project.h>

static char *cmd;

static void unitTest_00(t_test *test) 
{
	cmd = "-1 symdir";
	reset_sandbox();
	sandbox_cmd("mkdir mydir && ln -s mydir symdir && touch mydir/file{1..5}");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch a");
	sandbox_cmd("ln -s a b");
	cmd = "-1 b";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_02(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir a");
	sandbox_cmd("ln -s a b");
	sandbox_cmd("rm -rf a");
	cmd = "-1 b";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_03(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir a");
	sandbox_cmd("ln -s a b");
	sandbox_cmd("rm -rf a");
	cmd = "-l b";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_21_test_symlink(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
	SUITE_ADD_TEST(suite, unitTest_02);
	SUITE_ADD_TEST(suite, unitTest_03);
}
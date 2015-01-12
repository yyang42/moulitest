#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd;

	cmd = "";
	reset_sandbox();
	sandbox_cmd("mkdir dir{1..5} .hdir{1..5}");
	sandbox_cmd("touch dir1/file{1..5} dir1/.hfile{1..5}");
	sandbox_cmd("touch .hdir1/file{1..5} .hdir1/.hfile{1..5}");
	sandbox_cmd("touch .hdir1/file{1..5} .hdir1/.hfile{1..5}");
	sandbox_cmd("touch a && ln -s a symlink");

	cmd = "-lR .";

	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_30_test_opt_mix(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);

}
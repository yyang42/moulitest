#include <project.h>

static	char *cmd;
static void unitTest_00(t_test *test) 
{
	cmd = "-lR";

	reset_sandbox();

	sandbox_cmd("mkdir .dirA && mkdir .dirA/dirB && touch .dirA/dirB/file");

	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	cmd = "-1R";
	reset_sandbox();
	sandbox_cmd("mkdir .dirA && mkdir .dirA/dirB && touch .dirA/dirB/file");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_02(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir .dir1A .dir1B && mkdir .dir1A/dir2A && touch .dir1A/dir2A/file3");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_03(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir .dir1A .dir1B && mkdir .dir1A/dir2{A,B} && touch .dir1A/dir2A/file3A");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_buggy_ls_behaviors(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
	SUITE_ADD_TEST(suite, unitTest_02);
	SUITE_ADD_TEST(suite, unitTest_03);
}

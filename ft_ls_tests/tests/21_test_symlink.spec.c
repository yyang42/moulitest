#include <project.h>

UT_TEST(21_test_symlink)
{
	char *cmd;

	cmd = "-1 symdir";
	reset_sandbox();
	sandbox_cmd("mkdir mydir && ln -s mydir symdir && touch mydir/file{1..5}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch a");
	sandbox_cmd("ln -s a b");
	cmd = "-1 b";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir a");
	sandbox_cmd("ln -s a b");
	sandbox_cmd("rm -rf a");
	cmd = "-1 b";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("mkdir a");
	sandbox_cmd("ln -s a b");
	sandbox_cmd("rm -rf a");
	cmd = "-l b";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	// reset_sandbox();
	// sandbox_cmd("touch a");
	// sandbox_cmd("ln -s a b");
	// sandbox_cmd("rm a");
	// cmd = "-1l";
	// printf("\n========== ls ==========\n");
	// printf(ls(cmd));
	// printf("========= ft_ls ========\n");
	// printf(ft_ls(cmd));
	// printf("========================\n");
	// UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n===================\n");
	printf("%s", ls("-1 symdir"));
	printf("\n===================\n");
	printf("%s", ft_ls("-1 symdir"));
	printf("\n===================\n");
	*/
}

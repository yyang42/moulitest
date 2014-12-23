#include <project.h>

UT_TEST(bonus_06_test_opt_u)
{


	char *cmd = "-1tu";
	char *rcmd = "-1tur";
	char *lcmd = "-1lu";
	char *lscmd = "-1tlu";
	char *mix_cmd1 = "-1tSu";
	char *mix_cmd2 = "-1utS";

	reset_sandbox();
	sandbox_cmd("touch a b c d e && touch -at 201212101830.55 c");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	UT_ASSERT(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
	UT_ASSERT(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
	UT_ASSERT(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);
	UT_ASSERT(strcmp(ls(mix_cmd1), ft_ls(mix_cmd1)) == 0);
	UT_ASSERT(strcmp(ls(mix_cmd2), ft_ls(mix_cmd2)) == 0);

	reset_sandbox();
	sandbox_cmd("touch -at 201312101830.55 a && touch -at 201212101830.55 b && touch -at 201412101830.55 c");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
	UT_ASSERT(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
	UT_ASSERT(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
	UT_ASSERT(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch fileA{1..5} fileB{1..5} fileC{1..5} && touch -at 200012101830.55 fileA{1..5}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
	UT_ASSERT(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
	UT_ASSERT(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
	UT_ASSERT(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch -at 201312101830.55 a");
	sandbox_cmd("touch -at 201212101830.55 b");
	sandbox_cmd("touch -at 201412101830.55 c");
	sandbox_cmd("touch -at 201411221830.55 d");
	sandbox_cmd("touch -at 201405212033.55 e");
	sandbox_cmd("touch -at 201409221830.55 f");
	sandbox_cmd("touch -at 202007221830.55 g");
	sandbox_cmd("touch -at 300012101830.55 h");

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
	UT_ASSERT(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
	UT_ASSERT(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
	UT_ASSERT(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch a && touch -at 200012101830.55 a");
	sandbox_cmd("touch -at 201412101830.55 b");
	sandbox_cmd("ln b d");
	sandbox_cmd("ln -s c e");
	sandbox_cmd("ln -s a f");
	sandbox_cmd("touch -at 300012101830.55 c");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
	UT_ASSERT(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
	UT_ASSERT(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
	UT_ASSERT(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(lcmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(lcmd));
	printf("==================\n");
	*/
}


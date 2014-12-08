#include <project.h>

UT_TEST(08_test_opt_t)
{
	char *cmd = "-1t";

	reset_sandbox();
	sandbox_cmd("touch a b c d e && touch -t 201212101830.55 c");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch -t 201312101830.55 a && touch -t 201212101830.55 b && touch -t 201412101830.55 c");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch fileA{1..5} fileB{1..5} fileC{1..5} && touch -t 200012101830.55 fileA{1..5}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1lt";
	reset_sandbox();
	sandbox_cmd("touch -t 201312101830.55 a");
	sandbox_cmd("touch -t 201212101830.55 b");
	sandbox_cmd("touch -t 201412101830.55 c");
	sandbox_cmd("touch -t 201411221830.55 d");
	sandbox_cmd("touch -t 201405212033.55 e");
	sandbox_cmd("touch -t 201409221830.55 f");
	sandbox_cmd("touch -t 202007221830.55 g");
	sandbox_cmd("touch -t 300012101830.55 h");

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1lt";
	reset_sandbox();
	sandbox_cmd("touch -t 200012101830.55 a");
	sandbox_cmd("touch -t 201412101830.55 b");
	sandbox_cmd("ln b d");
	sandbox_cmd("ln -s c e");
	sandbox_cmd("ln -s a f");
	sandbox_cmd("touch -t 300012101830.55 c");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);


	cmd = "-1lt";
	reset_sandbox();

	sandbox_cmd("touch -t 201312101830.55 B");
	sandbox_cmd("touch -t 201312101830.55 a");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");

	*/
}
#include <project.h>

UT_TEST(bonus_02_test_opt_p)
{
	char *cmd;

	cmd = "-1pR";
	reset_sandbox();
	sandbox_cmd("mkdir mydir mydir2 && touch mydir/{aaa,bbb,ccc} && touch mydir2/{111,222,333}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1pR";
	reset_sandbox();
	sandbox_cmd("mkdir mydir{1..7} && touch mydir{1..7}/file{1..11}");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-lp /usr";
	reset_sandbox();
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-lp /usr/bin";
	reset_sandbox();
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1p /usr/bin";
	reset_sandbox();
	sandbox_cmd("mkdir mydir mydir2 && touch mydir/file{10..20} && touch mydir2/file{30..40}");
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}
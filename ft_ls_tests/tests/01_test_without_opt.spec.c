#include <project.h>

UT_TEST(01_test_without_opt)
{
	char *cmd;

	cmd = "-1";
	reset_sandbox();
	sandbox_cmd("touch aaa bbb ccc");
	UT_ASSERT(strequ(ft_ls(cmd), "aaa\nbbb\nccc\n"));

	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("touch -");

	cmd = "-1";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- -";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));
	
	cmd = "-1 --";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("mkdir -");

	cmd = "-1";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- -";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));
	
	cmd = "-1 --";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

/*
	printf("\n=====  ls  ========\n");
	printf(ls(cmd));
	printf("===== ft_ls =======\n");
	printf(ft_ls(cmd));
	printf("==================\n");
*/

}

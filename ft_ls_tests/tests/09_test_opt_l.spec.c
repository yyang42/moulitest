#include <project.h>

UT_TEST(09_test_opt_l)
{

	char *cmd = "-l";

	reset_sandbox();
	sandbox_cmd("touch a b c");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch a b c && echo 'coucou' > a &&  echo 'hello world' > b");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch a b c && echo 'coucou' > a &&  echo 'hello world' > b");
	sandbox_cmd("mkdir 111 222 333 444 && touch 111/{a,b,c} && echo 'eat pizza' > 111/a");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	reset_sandbox();
	sandbox_cmd("touch .a");
	sandbox_cmd("dd bs=2 count=14450 if=/dev/random of=.a  >/dev/null 2>&1");
	sandbox_cmd("ln -s .a b");
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);


	reset_sandbox();
	cmd = "-la dir";
	sandbox_cmd("mkdir -p dir/.hdir");
	sandbox_cmd("touch dir/.hdir/file");

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);


	reset_sandbox();
	cmd = "-l dir";
	sandbox_cmd("mkdir -p dir");
	sandbox_cmd("touch dir/.file touch dir/visible");
	sandbox_cmd("ln dir/.file sym0");
	sandbox_cmd("ln dir/.file sym1");
	sandbox_cmd("ln dir/.file sym2");
	sandbox_cmd("ln dir/.file sym3");
	sandbox_cmd("ln dir/.file sym4");
	sandbox_cmd("ln dir/.file sym5");
	sandbox_cmd("ln dir/.file sym6");
	sandbox_cmd("ln dir/.file sym7");
	sandbox_cmd("ln dir/.file sym8");
	sandbox_cmd("ln dir/.file sym9");
	sandbox_cmd("ln dir/.file sym10");

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}
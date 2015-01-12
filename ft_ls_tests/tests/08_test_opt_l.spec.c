#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-l";

	reset_sandbox();
	sandbox_cmd("touch a b c");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_1(t_test *test)
{
		char *cmd = "-l";


	reset_sandbox();
	sandbox_cmd("touch a b c && echo 'coucou' > a &&  echo 'hello world' > b");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_2(t_test *test)
{
	char *cmd = "-l";

	reset_sandbox();
	sandbox_cmd("touch a b c && echo 'coucou' > a &&  echo 'hello world' > b");
	sandbox_cmd("mkdir 111 222 333 444 && touch 111/{a,b,c} && echo 'eat pizza' > 111/a");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_3(t_test *test)
{
	char *cmd = "-l";
	
	reset_sandbox();
	sandbox_cmd("touch .a");
	sandbox_cmd("dd bs=2 count=14450 if=/dev/random of=.a  >/dev/null 2>&1");
	sandbox_cmd("ln -s .a b");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_4(t_test *test)
{
	char *cmd = "-l";

	reset_sandbox();
	cmd = "-la dir";
	sandbox_cmd("mkdir -p dir/.hdir");
	sandbox_cmd("touch dir/.hdir/file");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void simple_test_5(t_test *test)
{
	char *cmd = "-l";

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
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_08_test_opt_l(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);
	SUITE_ADD_TEST(suite, simple_test_2);
	SUITE_ADD_TEST(suite, simple_test_3);
	SUITE_ADD_TEST(suite, simple_test_4);
	SUITE_ADD_TEST(suite, simple_test_5);
}
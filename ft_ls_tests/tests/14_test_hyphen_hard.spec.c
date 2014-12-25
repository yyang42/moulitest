#include <project.h>

UT_TEST(14_test_hyphen_hard)
{

	char *cmd;

	reset_sandbox();
	sandbox_cmd("touch - file");

	cmd = "-1";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 --";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("touch -");

	cmd = "-1 -- -";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("touch - -- ---");

	cmd = "-1 -- --";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- ---";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- .";

	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("mkdir -- -file --file ---file");

	cmd = "-1 -- -file";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- --file";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- ---file";

	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("mkdir -");

	cmd = "-1";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("mkdir -");

	cmd = "-1 -- -";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("mkdir - -- ---");

	cmd = "-1 -- --";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- ---";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- .";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("mkdir -- -dir --dir ---dir");

	cmd = "-1 -- -dir";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- --dir";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	cmd = "-1 -- ---dir";
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));
	
}
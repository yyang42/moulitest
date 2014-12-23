#include <project.h>

UT_TEST(13_test_permissions)
{
	char *cmd;

	cmd = "-l";
	reset_sandbox();
	sandbox_cmd("touch a b c");
	sandbox_cmd("chmod 644 a");
	sandbox_cmd("chmod 755 b");
	sandbox_cmd("chmod 311 c");

	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));

	reset_sandbox();
	sandbox_cmd("mkdir a b c");
	sandbox_cmd("chmod 644 a");
	sandbox_cmd("chmod 755 b");
	sandbox_cmd("chmod 311 c");
	UT_ASSERT(strequ(ls(cmd), ft_ls(cmd)));
}
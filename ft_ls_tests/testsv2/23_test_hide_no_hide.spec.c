#include <project.h>

UT_TEST(23_test_hide_no_hide)
{
	char *cmd;

	cmd = "-lR";

	reset_sandbox();

	sandbox_cmd("mkdir .dirA && mkdir .dirA/dirB && touch .dirA/dirB/file");
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
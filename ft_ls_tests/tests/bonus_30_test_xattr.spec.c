#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd = "-l";

	reset_sandbox();
	sandbox_cmd("touch file && xattr -w theAnswerIs42 whatever_you_want file");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_30_test_xattr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);

}

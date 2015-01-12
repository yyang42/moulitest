#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd = "-1 / /";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_40_dir_root(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
}

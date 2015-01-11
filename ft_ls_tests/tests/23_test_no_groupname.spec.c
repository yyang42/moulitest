#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd;

	reset_sandbox();
	cmd = "-l /usr/share/doc";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_23_test_no_groupname(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);

}
#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd = "-l /";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_32_test_ACL(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
}

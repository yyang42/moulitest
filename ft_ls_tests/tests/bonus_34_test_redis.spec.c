#include <project.h>

static void unitTest_00(t_test *test) 
{
	char *cmd = "-l";

	cmd = "-1R /usr/share/norminette/rbx/2.1/gems/redis-3.1.0";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_34_test_redis(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
}

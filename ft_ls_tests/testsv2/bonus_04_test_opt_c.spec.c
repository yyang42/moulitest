#include <project.h>

UT_TEST(bonus_04_test_opt_c)
{
	reset_sandbox();
	char *cmd;

	cmd = "-1tc /usr/share";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1tcr /usr/share";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1ltc /usr/share";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1lcr /usr/share";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1lUr /usr/share";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1tu /usr/share";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1turl /usr/share";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

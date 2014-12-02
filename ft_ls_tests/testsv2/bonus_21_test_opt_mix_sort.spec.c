#include <project.h>

UT_TEST(bonus_21_test_opt_mix_sort)
{
	char *cmd;

	cmd = "-ARSUacdlprtu /usr/share";

	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-utrpldcaUSRA /usr/share";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

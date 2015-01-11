#include <project.h>

UT_TEST(bonus_34_test_wtf)
{
	char *cmd = "-l";

	cmd = "-1R /usr/share/norminette/rbx/2.1/gems/redis-3.1.0";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*UT_ASSERT_W(!"Test needed for './ft_ls -R /'");*/
}

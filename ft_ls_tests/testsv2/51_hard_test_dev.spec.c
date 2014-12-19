#include <project.h>

UT_TEST(51_hard_test_dev)
{
	char *cmd;
	reset_sandbox();

	cmd = "-1 /dev";
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/* io8 ignored because its minor device is not stable */

	cmd = "-1l /dev | grep -v io8 | grep -v autofs_nowait | sed -E \"s/ +/ /g\"";
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);
	cmd = "-1la /dev | grep -v io8 | grep -v autofs_nowait | sed -E \"s/ +/ /g\"";
	UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n===================\n");
	printf("%s", ls("-1R /dev"));
	printf("\n===================\n");
	printf("%s", ft_ls("-1R /dev"));
	printf("\n===================\n");
	*/

	/* next challenge
	// ls("-1R /dev");
	// ft_ls("-1R /dev");
	// UT_ASSERT(strcmp(ls("-1R /dev | tee > ls.out"), ft_ls("-1R /dev | tee > ft_ls.out")) == 0);
	 */
}
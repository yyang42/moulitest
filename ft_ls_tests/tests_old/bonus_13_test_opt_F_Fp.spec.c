#include <project.h>

UT_TEST(bonus_13_test_opt_F_Fp)
{
	char *cmd;

	reset_sandbox();
	sandbox_cmd("touch file");
	sandbox_cmd("mkdir dir");
	sandbox_cmd("mkfifo fifo");
	sandbox_cmd("touch exe exe1 exe2 && chmod 700 exe && chmod 070 exe1 && chmod 007 exe2");
	sandbox_cmd("ln -s file link &&ln -s dir link2 && ln -s testfifo link3");
	sandbox_cmd("ln -s exe link4");

	cmd = "-1F";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
	
	cmd = "-lF";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1pF";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-1Fp";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-lpF";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	cmd = "-lFp";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	** Test for socket with "=" sign
	*/
	cmd = "-lF /var/run";
	UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

	/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls(cmd));
	printf("==================\n");
	*/
}

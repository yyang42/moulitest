#include <project.h>


static	char *cmd;

static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file");
	sandbox_cmd("mkdir dir");
	sandbox_cmd("mkfifo fifo");
	sandbox_cmd("touch exe exe1 exe2 && chmod 700 exe && chmod 070 exe1 && chmod 007 exe2");
	sandbox_cmd("ln -s file link &&ln -s dir link2 && ln -s testfifo link3");
	sandbox_cmd("ln -s exe link4");

	cmd = "-1F";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	cmd = "-lF";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_02(t_test *test) 
{
	cmd = "-1pF";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_03(t_test *test) 
{
	cmd = "-1Fp";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_04(t_test *test) 
{
	cmd = "-lpF";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_05(t_test *test) 
{
	cmd = "-lFp";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_06(t_test *test) 
{
	cmd = "-lF /var/run";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_13_test_opt_F_Fp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
	SUITE_ADD_TEST(suite, unitTest_02);
	SUITE_ADD_TEST(suite, unitTest_03);
	SUITE_ADD_TEST(suite, unitTest_04);
	SUITE_ADD_TEST(suite, unitTest_05);
	SUITE_ADD_TEST(suite, unitTest_06);
}

#include <project.h>

static	char *cmd;

static void unitTest_00(t_test *test) 
{
	cmd = "-1d mydir mydir2";
	reset_sandbox();
	sandbox_cmd("mkdir mydir mydir2 && touch mydir/{aaa,bbb,ccc} && touch mydir2/{111,222,333}");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	cmd = "-1d mydir mydir2";
	reset_sandbox();
	sandbox_cmd("mkdir mydir mydir2 && touch mydir/file{10..20} && touch mydir2/file{30..40}");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_02(t_test *test) 
{
	cmd = "-1d mydir{1..7}";
	reset_sandbox();
	sandbox_cmd("mkdir mydir{1..7} && touch mydir{1..7}/file{1..11}");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_03(t_test *test) 
{
	cmd = "-1d mydir";
	reset_sandbox();
	sandbox_cmd("mkdir mydir && touch mydir/a");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_04(t_test *test) 
{
	cmd = "-ld ./mydir";
	reset_sandbox();
	sandbox_cmd("mkdir ./mydir && touch ./mydir/{a,b,c}");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_05(t_test *test) 
{
	cmd = "-1d ./mydir";
	reset_sandbox();
	sandbox_cmd("mkdir ./mydir && touch ./mydir/{a,b,c}");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_06(t_test *test) 
{
	cmd = "-1d .";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_07(t_test *test) 
{
	cmd = "-1d";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_08(t_test *test) 
{
	cmd = "-ld .";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);

}

static void unitTest_09(t_test *test) 
{
	cmd = "-ld";
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_bonus_01_test_opt_d(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
	SUITE_ADD_TEST(suite, unitTest_02);
	SUITE_ADD_TEST(suite, unitTest_03);
	SUITE_ADD_TEST(suite, unitTest_04);
	SUITE_ADD_TEST(suite, unitTest_05);
	SUITE_ADD_TEST(suite, unitTest_06);
	SUITE_ADD_TEST(suite, unitTest_07);
	SUITE_ADD_TEST(suite, unitTest_08);
	SUITE_ADD_TEST(suite, unitTest_09);
}
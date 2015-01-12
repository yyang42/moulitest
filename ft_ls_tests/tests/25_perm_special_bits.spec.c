#include <project.h>

static	char *cmd = "-l";

static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file1 && chmod 0777 file1");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file2 && chmod 1777 file2");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_02(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file3 && chmod 2777 file3");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_03(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file4 && chmod 3777 file4");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_04(t_test *test) 
{

	reset_sandbox();
	sandbox_cmd("touch file5 && chmod 4777 file5");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_05(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file6 && chmod 5777 file6");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_06(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file7 && chmod 6777 file7");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_07(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file8 && chmod 7777 file8");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_08(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file9 && chmod 0000 file9");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_09(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file10 && chmod 1000 file10");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_10(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file11 && chmod 2000 file11");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_11(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file12 && chmod 3000 file12");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_12(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file13 && chmod 4000 file13");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_13(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file14 && chmod 5000 file14");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}


static void unitTest_14(t_test *test) 
{
		reset_sandbox();
	sandbox_cmd("touch file15 && chmod 6000 file15");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}


static void unitTest_15(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch file16 && chmod 7000 file16");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_25_perm_special_bits(t_suite *suite)
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
	SUITE_ADD_TEST(suite, unitTest_10);
	SUITE_ADD_TEST(suite, unitTest_11);
	SUITE_ADD_TEST(suite, unitTest_12);
	SUITE_ADD_TEST(suite, unitTest_13);
	SUITE_ADD_TEST(suite, unitTest_14);
	SUITE_ADD_TEST(suite, unitTest_15);

}
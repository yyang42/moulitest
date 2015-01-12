#include <project.h>

static char *cmd = "-l";

static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir1 && chmod 0777 dir1");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir2 && chmod 1777 dir2");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_02(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir3 && chmod 2777 dir3");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_03(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir4 && chmod 3777 dir4");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_04(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir5 && chmod 4777 dir5");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_05(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir6 && chmod 5777 dir6");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_06(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir7 && chmod 6777 dir7");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_07(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir9 && chmod 0000 dir9");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_08(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir9 && chmod 0000 dir9");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_09(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir10 && chmod 1000 dir10");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_10(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir11 && chmod 2000 dir11");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_11(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir12 && chmod 3000 dir12");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_12(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir13 && chmod 4000 dir13");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_13(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir14 && chmod 5000 dir14");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_14(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir15 && chmod 6000 dir15");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_15(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir  dir16 && chmod 7000 dir16");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_26_perm_special_bits_dir(t_suite *suite)
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
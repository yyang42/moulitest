#include <project.h>

static char *cmd;

static void unitTest_00(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch -- - -- ---");
	cmd = "-1 -- -- --";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
static void unitTest_01(t_test *test)
{
	cmd = "-1 - - -";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
static void unitTest_02(t_test *test)
{
	cmd = "-1 -- - -- ---";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
static void unitTest_03(t_test *test)
{
	cmd = "-1 - -- ---";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
static void unitTest_04(t_test *test)
{
	cmd = "-1 -- - ---";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_05(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("mkdir -- - -- ---");
	cmd = "-1 -- -- --";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
static void unitTest_06(t_test *test)
{
	cmd = "-1 - - -";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
static void unitTest_07(t_test *test)
{
	cmd = "-1 -- - -- ---";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
static void unitTest_08(t_test *test)
{
	cmd = "-1 - -- ---";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}
static void unitTest_09(t_test *test)
{
	cmd = "-1 -- - ---";
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_14_test_hyphen_harder(t_suite *suite)
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
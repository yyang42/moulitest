#include <project.h>

static	char *cmd;
static	char *ls_out_str;
static	char *ft_ls_out_str;

static void unitTest_00(t_test *test)
{
	cmd = "\"\"";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test)
{
	cmd = "-l \"\"";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_02(t_test *test)
{
	cmd = "-l \"\" -R";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_03(t_test *test)
{
	cmd = "-lR . \"\" .";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_04(t_test *test)
{
	cmd = "-~ \"\"";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	ft_ls_out_str = strip_illegal_opt_err(ft_ls(cmd));
	ls_out_str = strip_illegal_opt_err(ls(cmd));
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls_out_str, ft_ls_out_str) == 0);
}

static void unitTest_05(t_test *test)
{
	cmd = "\"\" -~";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	ft_ls_out_str = strip_illegal_opt_err(ft_ls(cmd));
	ls_out_str = strip_illegal_opt_err(ls(cmd));
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls_out_str, ft_ls_out_str) == 0);
}

static void unitTest_06(t_test *test)
{
	cmd = "aa \"\" bb";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_07(t_test *test)
{
	cmd = "\"\" aa bb";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_08(t_test *test)
{
	cmd = "aa bb \"\"";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_09(t_test *test)
{
	cmd = "aa \"\" dne";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_10(t_test *test)
{
	cmd = "dne \"\" aa";
	reset_sandbox();
	sandbox_cmd("mkdir dirA && touch aa bb cc dirA/aa dirA/bb dirA/cc");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_69_empty_argument_tests(t_suite *suite)
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
}

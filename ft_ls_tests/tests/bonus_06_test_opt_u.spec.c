#include <project.h>

static	char *cmd = "-1tu";
static	char *rcmd = "-1tur";
static	char *lcmd = "-1lu";
static	char *lscmd = "-1tlu";
static	char *mix_cmd1 = "-1tSu";
static	char *mix_cmd2 = "-1utS";

static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch a b c d e && touch -at 201212101830.55 c");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_01(t_test *test) 
{
	mt_assert(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
}

static void unitTest_02(t_test *test) 
{
	mt_assert(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
}

static void unitTest_03(t_test *test) 
{
	mt_assert(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);
}

static void unitTest_04(t_test *test) 
{
	mt_assert(strcmp(ls(mix_cmd1), ft_ls(mix_cmd1)) == 0);
}

static void unitTest_05(t_test *test) 
{
	mt_assert(strcmp(ls(mix_cmd2), ft_ls(mix_cmd2)) == 0);
}

static void unitTest_06(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch -at 201312101830.55 a && touch -at 201212101830.55 b && touch -at 201412101830.55 c");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_07(t_test *test) 
{
	mt_assert(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
}

static void unitTest_08(t_test *test) 
{
	mt_assert(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
}

static void unitTest_09(t_test *test) 
{
	mt_assert(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);
}

static void unitTest_10(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch fileA{1..5} fileB{1..5} fileC{1..5} && touch -at 200012101830.55 fileA{1..5}");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_11(t_test *test) 
{
	mt_assert(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
}

static void unitTest_12(t_test *test) 
{
	mt_assert(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
}

static void unitTest_13(t_test *test) 
{
	mt_assert(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);
}

static void unitTest_14(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch -at 201312101830.55 a");
	sandbox_cmd("touch -at 201212101830.55 b");
	sandbox_cmd("touch -at 201412101830.55 c");
	sandbox_cmd("touch -at 201411221830.55 d");
	sandbox_cmd("touch -at 201405212033.55 e");
	sandbox_cmd("touch -at 201409221830.55 f");
	sandbox_cmd("touch -at 202007221830.55 g");
	sandbox_cmd("touch -at 300012101830.55 h");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_15(t_test *test) 
{
	mt_assert(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
}

static void unitTest_16(t_test *test) 
{
	mt_assert(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
}

static void unitTest_17(t_test *test) 
{
	mt_assert(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);
}

static void unitTest_18(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch a && touch -at 200012101830.55 a");
	sandbox_cmd("touch -at 201412101830.55 b");
	sandbox_cmd("ln b d");
	sandbox_cmd("ln -s c e");
	sandbox_cmd("ln -s a f");
	sandbox_cmd("touch -at 300012101830.55 c");
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

static void unitTest_19(t_test *test) 
{
	mt_assert(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);
}

static void unitTest_20(t_test *test) 
{
	mt_assert(strcmp(ls(lcmd), ft_ls(lcmd)) == 0);
}

static void unitTest_21(t_test *test) 
{
	mt_assert(strcmp(ls(lscmd), ft_ls(lscmd)) == 0);
}

void	suite_bonus_06_test_opt_u(t_suite *suite)
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
	SUITE_ADD_TEST(suite, unitTest_16);
	SUITE_ADD_TEST(suite, unitTest_17);
	SUITE_ADD_TEST(suite, unitTest_18);
	SUITE_ADD_TEST(suite, unitTest_19);
	SUITE_ADD_TEST(suite, unitTest_20);
	SUITE_ADD_TEST(suite, unitTest_21);
}
#include <project.h>

static void unitTest_00(t_test *test) 
{
	reset_sandbox();
	mt_assert(strcmp(ls("-lR /usr/bin"), ft_ls("-lR /usr/bin")) == 0);
}

static void unitTest_01(t_test *test) 
{
	mt_assert(strcmp(ls("-l /usr"), ft_ls("-l /usr")) == 0);
}

static void unitTest_02(t_test *test) 
{
	mt_assert(strcmp(ls("-1t /usr"), ft_ls("-1t /usr")) == 0);
}

static void unitTest_03(t_test *test) 
{
	mt_assert(strcmp(ls("-tl /usr"), ft_ls("-tl /usr")) == 0);
}

void	suite_50_hard_test_user_bin(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
	SUITE_ADD_TEST(suite, unitTest_02);
	SUITE_ADD_TEST(suite, unitTest_03);
}
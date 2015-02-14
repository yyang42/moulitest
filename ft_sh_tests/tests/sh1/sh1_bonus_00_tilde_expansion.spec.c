#include <project.h>

static void simple(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"cd /\n"
		"cd ~\n"
		"pwd\n"
		"exit\n",
		"grep \"$HOME\"");
}

void	suite_sh1_bonus_00_tilde_expansion(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
}

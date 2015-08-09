#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-1t";

	cmd = "-1tR";
	reset_sandbox();

	sandbox_cmd("mkdir -p sbox/level1_{1..2}/level2_{1..2}/level3_{1..2}");
	sandbox_cmd("mkdir -p sbox1/level1_{1..2}/level2_{1..2}/level3_{1..2}");
	sandbox_cmd("mkdir -p sbox/level1_1 sbox/level1_1/level2_1");
	sandbox_cmd("touch -t 201212101830.55 sbox/c_lvl1");
	sandbox_cmd("touch -t 201212101830.55 sbox/level1_1/c_lvl2");
	sandbox_cmd("touch -t 201212101830.55 sbox/level1_1/level2_1/c_lvl3");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_07_test_opt_tR_bis(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
}

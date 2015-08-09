#include <project.h>

static void simple_test_0(t_test *test)
{
	char *cmd = "-1t";

	cmd = "-1tR";
	reset_sandbox();

	sandbox_cmd("mkdir -p sbox/lvl1_{1..2}/lvl2_{1..2}/lvl3_{1..2}");
	sandbox_cmd("mkdir -p sbox1/lvl1_{1..2}/lvl2_{1..2}/lvl3_{1..2}");
	sandbox_cmd("touch -t 201212101830.55 sbox/c_lvl1");
	sandbox_cmd("touch -t 201212101830.55 sbox/lvl1_1/c_lvl2");
	sandbox_cmd("touch -t 201212101830.55 sbox/lvl1_1/lvl2_1/c_lvl3");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls(cmd), ft_ls(cmd)) == 0);
}

void	suite_07_test_opt_tR_bis(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
}

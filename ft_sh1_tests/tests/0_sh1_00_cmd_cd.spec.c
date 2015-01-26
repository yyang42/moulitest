#include <project.h>

static void failing_test(t_test *test)
{
	test->debug = 1;
	mt_assert_sh(test,  "cd /usr\n"
						"pwd\n"
						"exit\n", "grep /usr");
}

void	suite_0_sh1_00_cmd_cd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, failing_test);
}

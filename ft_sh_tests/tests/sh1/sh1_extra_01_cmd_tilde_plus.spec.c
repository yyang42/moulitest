#include <project.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"cd /usr\n"
		"echo ~+\n"
		"exit\n",
		"grep '/usr'");
}

static void test_tilde_minus(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		"cd /usr\n"
		"cd /\n"
		"echo ~-\n"
		"exit\n",
		"grep '/usr'");
}

void	suite_sh1_extra_01_cmd_tilde_plus(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_tilde_minus);
}

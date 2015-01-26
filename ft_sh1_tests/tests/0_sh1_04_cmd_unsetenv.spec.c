#include <project.h>

static void simple_unsetenv_test(t_test *test)
{
	test->debug = 1;
	mt_assert_sh(test, "setenv aaa 111\nunsetenv aaa\nenv\nexit\n", "grep '^aaa='");
}

void	suite_0_sh1_04_cmd_unsetenv(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_unsetenv_test);
}

#include <project.h>

static void simple_test_0(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch aaa");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls("-l aaa"), ft_ls("-l aaa")) == 0);
}

static void simple_test_1(t_test *test)
{

	reset_sandbox();
	sandbox_cmd("touch aaa");
	// print_ls_debug(cmd);
	mt_assert(strcmp(ls("-l aaa"), ft_ls("-l aaa")) == 0);
}

void	suite_11_test_single_file(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_0);
	SUITE_ADD_TEST(suite, simple_test_1);

}
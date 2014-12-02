#include <project.h>

UT_TEST(11_test_single_file)
{
	reset_sandbox();
	sandbox_cmd("touch aaa");
	UT_ASSERT(strcmp(ls("-l aaa"), ft_ls("-l aaa")) == 0);

	reset_sandbox();
	sandbox_cmd("touch aaa");
	UT_ASSERT(strcmp(ls("-l aaa"), ft_ls("-l aaa")) == 0);
}
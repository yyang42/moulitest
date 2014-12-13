#include <project.h>

UT_TEST(50_hard_test_user_bin)
{
	reset_sandbox();
	UT_ASSERT_W(strcmp(ls("-lR /usr/bin"), ft_ls("-lR /usr/bin")) == 0);
	UT_ASSERT(strcmp(ls("-l /usr"), ft_ls("-l /usr")) == 0);
	UT_ASSERT(strcmp(ls("-1t /usr"), ft_ls("-1t /usr")) == 0);
	UT_ASSERT(strcmp(ls("-tl /usr"), ft_ls("-tl /usr")) == 0);
}
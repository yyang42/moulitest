#include <test.h>
#include <stdio.h>
#include <mt.h>

void	test_assert_prep(t_test	*test, char *cond, char *msg, int expected_signum)
{
	test->last_assert_cond = cond;
	test->msg = msg;
	test->expected_signum = expected_signum;
}

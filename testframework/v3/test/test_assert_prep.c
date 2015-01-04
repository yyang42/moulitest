#include <test.h>
#include <stdio.h>
#include <mt.h>

void	test_assert_prep(t_test	*test, char *cond, char *msg)
{
	test->last_assert_cond = cond;
	test->msg = msg;
}

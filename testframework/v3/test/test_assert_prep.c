#include <test.h>
#include <stdio.h>
#include <mt.h>

void	test_assert_prep(t_test	*test, char *cond)
{
	test->last_assert_cond = cond;
}

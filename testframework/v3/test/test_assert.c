#include <test.h>
#include <stdio.h>
#include <mt.h>

void	test_assert(t_test	*test, int cond_res)
{
	if (cond_res == 0)
		abort();
	(void)test;
}

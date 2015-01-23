#include <test.h>
#include <stdio.h>
#include <signal.h>
#include <mt.h>

void	test_assert(t_test	*test, int cond_res)
{
	if (cond_res == 0)
		raise(SIGUSR1);
	(void)test;
}

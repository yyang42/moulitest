#include <mt.h>
#include <test.h>
#include <stdio.h>
#include <unistd.h>

void	test_exec(t_test	*test)
{
	test->fn(test);
	ffprintf(".");
  	usleep(500 * 1000);
}

#include <mt.h>
#include <test.h>
#include <stdio.h>
#include <unistd.h>


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <setjmp.h>

jmp_buf env_buffer;

static void sig_handler(int signum)
{
	longjmp(env_buffer, 1);
	(void)signum;
}

static void	test_exec_do(t_test	*test)
{
	if (!setjmp( env_buffer ))
	{
		signal(SIGABRT, sig_handler);
		test->fn(test);
		test->is_success = 1;
	}
	else
	{
		test->is_success = 0;
	}
}

void	test_exec(t_test	*test)
{
	test_exec_do(test);
	test_print(test);
  	usleep(500 * 1000);
}

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
	signal(SIGABRT, sig_handler);
	if (setjmp(env_buffer))
	{
		test->is_fail = 1;
	}
	else
	{
		test->fn(test);
		test->is_fail = 0;
	}
}

void	test_exec(t_test	*test)
{
	test_exec_do(test);
}

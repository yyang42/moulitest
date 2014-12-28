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
	longjmp(env_buffer, signum);
	(void)signum;
}

static void	test_exec_do(t_test	*test)
{
	int sig;

	signal(SIGABRT, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(SIGBUS, sig_handler);
	if ((sig = setjmp(env_buffer)))
	{
		test->is_fail = 1;
		test->sig = sig;
	}
	else
	{
		test->fn(test);
		test->is_fail = 0;
	}
}

void	test_exec(t_lst_elem *elem)
{
	t_test	*test;

	test = elem->data;
	test_exec_do(test);
	test_print(elem);
  	// usleep(100 * 1000);
}

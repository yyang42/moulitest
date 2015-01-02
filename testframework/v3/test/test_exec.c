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
#include <capture.h>

jmp_buf env_buffer;

#define TIMEOUT_DELAY 2

static void sig_handler_jmp(int signum)
{
	longjmp(env_buffer, signum);
} 

static void	test_exec_do(t_test	*test)
{
	signal(SIGABRT, sig_handler_jmp);
	signal(SIGSEGV, sig_handler_jmp);
	signal(SIGBUS, sig_handler_jmp);
	signal(SIGALRM, sig_handler_jmp);

	test->is_fail = 0;
	if ((test->sig = setjmp(env_buffer)))
	{
		test->is_fail = 1;
	}
	else
	{
		alarm(TIMEOUT_DELAY);
		test->fn(test);
	}
	capture_close_saved_stdout();
}

void	test_exec(t_lst_elem *elem)
{
	t_test	*test;

	test = elem->data;
	test_exec_do(test);
	test_print(elem);
  	// usleep(300 * 1000);
}

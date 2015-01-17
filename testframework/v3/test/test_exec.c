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

# define DEFAULT_TIMEOUT_UINTERVAL 1 * 1000 * 1000

jmp_buf env_buffer;

static void sig_handler_jmp(int signum)
{
	longjmp(env_buffer, signum);
} 

static void	test_exec_do(t_test	*test)
{
	signal(SIGUSR1, sig_handler_jmp);
	signal(SIGABRT, sig_handler_jmp);
	signal(SIGSEGV, sig_handler_jmp);
	signal(SIGBUS, sig_handler_jmp);
	signal(SIGALRM, sig_handler_jmp);

	test->is_fail = 0;
	if (!(test->sig = setjmp(env_buffer)))
	{
		ualarm(test->timeout, DEFAULT_TIMEOUT_UINTERVAL);
		test->fn(test);
	}
	if (test->expected_signum != test->sig)
		test->is_fail = 1;
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

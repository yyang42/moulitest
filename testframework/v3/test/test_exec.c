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

// static int getset_signnum(int signum)
// {
// 	static int	save;
// 	int			tmp;

// 	if (signum)
// 	{
// 		save = signum;
// 		return (save);
// 	}
// 	tmp = save;
// 	save = 0;
// 	return (tmp);
// }

// static void sig_handler(int signum)
// {
// 	getset_signnum(signum);
// }
// // static void raise_abord(int signum)
// // {
// // 	raise(SIGABRT);
// // 	(void)signum;
// // }

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
	// if (saved_stdout != -1)
	// {
	// 	fprintf(stderr, "== close %d ==\n", saved_stdout);
	// 	dup2(saved_stdout, 1);
	// 	close(saved_stdout); /* important ! */
	// 	saved_stdout = -1;
	// }
}

void	test_exec(t_lst_elem *elem)
{
	t_test	*test;

	test = elem->data;
	test_exec_do(test);
	test_print(elem);
  	// usleep(300 * 1000);
}

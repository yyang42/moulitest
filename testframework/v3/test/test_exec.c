#include <mt.h>
#include <test.h>
#include <stdio.h>
#include <unistd.h>


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
// #include <setjmp.h>
// jmp_buf env_buffer;

static int getset_signnum(int signum)
{
	static int	save;
	int			tmp;

	if (signum)
	{
		save = signum;
		return (save);
	}
	tmp = save;
	save = 0;
	return (tmp);
}

static void sig_handler(int signum)
{
	getset_signnum(signum);
}

static void	test_exec_do(t_test	*test)
{
	int sig;

	signal(SIGABRT, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(SIGBUS, sig_handler);

	test->fn(test);
	test->is_fail = 0;

	if ((sig = getset_signnum(0)))
	{
		test->is_fail = 1;
		test->sig = sig;
	}
}

void	test_exec(t_lst_elem *elem)
{
	t_test	*test;

	test = elem->data;
	test_exec_do(test);
	test_print(elem);
  	// usleep(300 * 1000);
}

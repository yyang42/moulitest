#include "unit_test.h"
#include <stdlib.h>
#include <setjmp.h>

ut_test_list_t	*ut_tests = 0;
jmp_buf			ut_env;
char			*ut_last_err;

void				ut_sigsegv_(int u)
{
	(void)u;
	longjmp(ut_env, 1);
}

ut_test_list_t		*ut_create_list_(ut_test f, char *n)
{
	ut_test_list_t	*tmp;

	tmp = malloc(sizeof(ut_test_list_t));
	tmp->next = 0;
	tmp->test = f;
	tmp->name = n;
	return (tmp);
}

void			ut_add_test_(ut_test f, char *n)
{
	ut_test_list_t	*tmp;

	if (!ut_tests)
	{
		ut_tests = ut_create_list_(f, n);
	}
	else
	{
		tmp = ut_tests;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = ut_create_list_(f, n);
	}
}

int			ut_run_all_tests_(void)
{
	int		_test_fails;
	int		count;
	int		ret;
	ut_test_list_t	*tmp;

	signal(SIGBUS, &ut_sigsegv_);
	signal(SIGSEGV, &ut_sigsegv_);
	signal(SIGILL, &ut_sigsegv_) ;
	_test_fails = 0;
	count = 0;
	if (!ut_tests)
	{
		return (0);
	}
	puts("[ \033[36;1m------STARTING ALL UNIT TESTS------\033[0m ]");
	tmp = ut_tests;
	while (tmp)
	{
		ret = 0;
		if (setjmp(ut_env))
		{
			UT_SEGV(tmp);
			_test_fails++;
		}
		else
		{
			UT_RUN_TEST(tmp, &ret);
		}
		count++;
		tmp = tmp->next;
	}
	printf("\033[37;1mEnd of test : %d out of %d test passed.\033[0m\n", count - _test_fails, count);
	puts("[ \033[36;1m---------END OF UNIT TESTS---------\033[0m ]");
	return (_test_fails);
}


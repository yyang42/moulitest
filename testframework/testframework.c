#include <testframework.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>

ut_test_list_t	*ut_tests = 0;
jmp_buf			ut_env;
char			*ut_last_err;
char			*ut_last_cond;
int				is_warning;
char			ut_test_symbol[100000];

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
	tmp->is_fail = 0;
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


void	ut_print_result_line(char *test_name, char *res_level, char *dots, char *message)
{
	printf("%s%s%s%s", test_name, res_level, dots, message);
}

void	ut_run_test(ut_test_list_t *t_, int *i_, int *_test_fails)
{
	char *color;
	char *res_msg;

	printf("%s%-30s", "["C_YELLOW"UT"C_CLEAR"] ", t_->name);
	t_->test(i_);
	if(*(i_) == 1) {
		color = C_RED;
		res_msg = "FAIL";
		(*_test_fails)++;
	}
	else {
		color = C_GREEN;
		res_msg = "Ok !";
	}
	printf("[%s%s"C_CLEAR"] ", color, res_msg);
	printf("%s", ut_test_symbol);
	if (ut_last_err)
		printf(" ERROR: %s", ut_last_err);
	printf("\n");
	*ut_test_symbol = '\0';
	ut_last_err = NULL;
	ut_last_cond = '\0';
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
	puts("[ "C_CYAN"-------STARTING ALL UNIT TESTS-------"C_CLEAR" ]");
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
			ut_run_test(tmp, &ret, &_test_fails);
		}
		count++;
		tmp = tmp->next;
	}
	printf(C_WHITE"End of test : %d out of %d test passed."C_CLEAR"\n", count - _test_fails, count);
	puts("[ "C_CYAN"----------END OF UNIT TESTS----------"C_CLEAR" ]");
	return (_test_fails);
}

int	strequ(const char *s1, const char *s2)
{
	return (s1 && s2 && strcmp(s1, s2) == 0);
}
#include <suite.h>
#include <test.h>
#include <stdio.h>
#include <lst.h>

static void		suite_print_prefix(t_suite *suite)
{
	fprintf(stdout, "-> %s : ", suite->name);
}

static void		suite_print_suffix(t_suite *suite)
{
	fprintf(stdout, "\n");
	(void)suite;
}

static void		suite_print_first_failure(t_suite *suite)
{
	t_lst_elem	*elem;
	t_test		*test;

	elem = suite->tests->elems;
	while (elem)
	{
		test = elem->data;
		if (test->is_fail)
		{
			fprintf(stdout, " %s: %s",
				test->name,
				test->last_assert_cond);
			break ;
		}
		elem = elem->next;
	}
}

void			suite_exec(t_suite *suite)
{
	suite_print_prefix(suite);
	suite->fn(suite);
	lst_iter(suite->tests, (void *)test_exec);
	suite_print_first_failure(suite);
	suite_print_suffix(suite);
}

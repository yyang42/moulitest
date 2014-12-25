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

void			suite_exec(t_suite *suite)
{
	suite_print_prefix(suite);
	suite->fn(suite);
	lst_iter(suite->tests, (void *)test_exec);
	suite_print_suffix(suite);
}

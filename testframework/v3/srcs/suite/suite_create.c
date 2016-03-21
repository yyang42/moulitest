#include <suite.h>
#include <stdio.h>

t_suite			*suite_create(char *name, t_suite_fn *fn)
{
	t_suite	*suite;

	suite = malloc(sizeof(t_suite));
	bzero(suite, sizeof(t_suite));
	suite->name = strdup(name);

	suite->tests = mt_lst_init();
	suite->fn = fn;
	return (suite);
}

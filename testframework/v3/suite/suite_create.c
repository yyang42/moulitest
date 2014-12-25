#include <suite.h>

t_suite			*suite_create(char *name, t_suite_fn *fn)
{
	t_suite	*suite;

	suite = (t_suite *)malloc(sizeof(t_suite));
	suite->name = strdup(name);

	suite->tests = lst_init();
	suite->fn = fn;
	return (suite);
}

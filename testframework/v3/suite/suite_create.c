#include <suite.h>

t_suite			*suite_create(char *name, t_suite_fn *fn)
{
	t_suite	*suite;

	suite = (t_suite *)malloc(sizeof(t_suite));
	suite->name = strdup(name);

	suite->tests = (t_test **)malloc(sizeof(t_test) * MAX_TESTS_PER_SUITE);
	suite->fn = fn;
	suite->tests[0] = NULL;	// suite->name = strdup(name);
	suite->fn(suite);
	return (suite);
}

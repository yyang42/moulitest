#include <test.h>
#include <stdio.h>

t_test	*test_create(char *name, t_test_fn *fn, int timeout)
{
	t_test	*test;	

	test = (t_test *)malloc(sizeof(t_test));
	test->name = strdup(name);
	test->sig = 0;
	test->fn = fn;
	test->debug = 0;
	test->timeout = timeout;
	return (test);
}

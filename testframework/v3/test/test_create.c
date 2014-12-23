#include <test.h>

t_test						*test_create(char *name)
{
	t_test	*test;	

	test = (t_test *)malloc(sizeof(t_test));
	test->name = strdup(name);
	return (test);
}

#include <test.h>

t_test						*test_create(char *name, int is_success)
{
	t_test	*test;	

	test = (t_test *)malloc(sizeof(t_test));
	test->name = strdup(name);
	test->is_success = is_success;
	return (test);
}

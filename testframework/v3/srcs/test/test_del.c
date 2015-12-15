#include <test.h>
#include <stdio.h>

void				test_del(t_test *test)
{
	free(test->name);
	free(test);
}

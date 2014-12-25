#include <test.h>
#include <stdio.h>
#include <mt.h>

void	test_assert(t_test	*test, int is_success)
{
	if (!is_success)
		abort();
	// fprintf(stdout, "[%s]", name);
	(void)test;
	(void)is_success;
}

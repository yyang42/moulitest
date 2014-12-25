#include <test.h>
#include <stdio.h>

void	test_print(t_test	*test)
{
	printf("%s", test->is_fail ? "X" : ".");
	fflush(stdout);
}

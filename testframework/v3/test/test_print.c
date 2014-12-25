#include <test.h>
#include <stdio.h>
#include <color.h>

void	test_print(t_test	*test)
{
	char *symbol;

	symbol = test->is_fail ? C_RED "X" C_CLEAR : C_GREEN "." C_CLEAR;
	printf(symbol);
	fflush(stdout);
}

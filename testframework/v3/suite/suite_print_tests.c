#include <suite.h>
#include <stdio.h>

void			suite_print_tests(t_suite *suite)
{
	t_test	**tests;

	tests = suite->tests;
	while(*tests)
		printf("- test : %s\n", (*tests++)->name);
}

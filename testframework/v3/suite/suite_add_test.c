#include <suite.h>
#include <stdio.h>

char *mystr = "4324";

void			suite_add_test(t_suite *suite, t_test	*test)
{
	t_test	**tests;

	tests = suite->tests;
	while(*tests)
	{
		tests++;
	}
	test_print(test);
	*tests = test;
	++tests;
	*tests = NULL;
}

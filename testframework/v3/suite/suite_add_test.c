#include <suite.h>

void			suite_add_test(t_suite *suite, t_test	*test)
{
	t_test	**tests;

	tests = suite->tests;
	while(*tests)
		tests++;
	*tests = test;
	++tests;
	*tests = NULL;
}
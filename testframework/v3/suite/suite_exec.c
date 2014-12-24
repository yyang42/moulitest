#include <suite.h>
#include <stdio.h>

// static void			suite_add_tests(t_suite *suite)
// {
// 	t_test	**tests;
// 	t_test 	*test;

// 	tests = suite->tests;
// 	while(*tests)
// 	{
// 		test = *tests;
// 		printf("%s", test->is_success ? "." : "X");
// 		tests++;
// 	}
// }

void			suite_exec(t_suite *suite)
{
	suite->fn(suite);
	// suite_add_tests(suite);
}

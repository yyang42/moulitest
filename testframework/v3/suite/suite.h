#ifndef SUITE_H
# define SUITE_H

#include <string.h>
#include <stdlib.h>
#include <test.h>
# define MAX_TESTS_PER_SUITE 1000


typedef struct				s_suite
{
	char					*name;
	t_test					**tests;
	int						x_success_count;
	int						x_warning_count;
}							t_suite;

t_suite			*suite_create(char *name);
void			suite_add_test(t_suite *suite, t_test	*test);
void			suite_print_tests(t_suite *suite);

#endif
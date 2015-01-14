#ifndef SUITE_H
# define SUITE_H

#include <string.h>
#include <stdlib.h>
#include <test.h>
#include <lst.h>
# define MAX_TESTS_PER_SUITE 1000

struct s_suite;

typedef	void (t_suite_fn)(struct s_suite *);

typedef struct				s_suite
{
	char					*name;
	t_suite_fn				*fn;
	t_lst					*tests;
	int						x_success_count;
	int						x_warning_count;
}							t_suite;

t_suite			*suite_create(char *name, t_suite_fn *fn);
void			suite_add_test(t_suite *suite, t_test	*test);
void			suite_exec(t_lst_elem *elem);
size_t			suite_count_failed_tests(t_suite *suite);
int				suite_filter_failed(t_suite	*suite);
size_t			suite_count_tests(t_suite *suite);

#endif

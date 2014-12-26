#ifndef TEST_H
# define TEST_H

#include <string.h>
#include <stdlib.h>

typedef struct s_test t_test;

typedef	void (t_test_fn)(t_test *);

typedef struct				s_test
{
	char					*name;
	char					*last_assert_cond;
	t_test_fn				*fn;
	int						is_fail;
	int						test_type;
	int						sig;
}							t_test;

t_test						*test_create(char *name, t_test_fn *fn);
void						test_print(t_test *test);
void						test_exec(t_test *test);
void						test_assert(t_test	*test, int is_fail);
void						test_assert_prep(t_test	*test, char *cond);
int							test_filter_failed(t_test *test);
char						*test_get_failure_type(t_test *test);

#endif
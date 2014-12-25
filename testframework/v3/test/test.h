#ifndef TEST_H
# define TEST_H

#include <string.h>
#include <stdlib.h>

typedef struct s_test t_test;

typedef	void (t_test_fn)(t_test *);

typedef struct				s_test
{
	char					*name;
	t_test_fn				*fn;
	int						is_success;
	int						test_type;
}							t_test;

t_test						*test_create(char *name, t_test_fn *fn);
void						test_print(t_test *test);
void						test_exec(t_test *test);

#endif
#ifndef TEST_H
# define TEST_H

# include <string.h>
# include <stdlib.h>
# include <lst.h>

struct s_test;

typedef	void (t_test_fn)(struct s_test *);

typedef struct				s_test
{
	char					*name;
	char					*last_assert_cond;
	char					*msg;
	t_test_fn				*fn;
	int						is_fail;
	int						expected_signum;
	int						test_type;
	int						sig;
	int						debug;
	int						timeout;
}							t_test;

t_test						*test_create(char *name, t_test_fn *fn, int timeout);
void						test_print(t_lst_elem *elem);
void						test_exec(t_lst_elem *elem);
void						test_assert(t_test	*test, int is_fail);
void						test_assert_prep(t_test	*test, char *cond, char *msg, int expected_signum);
int							test_filter_failed(t_test *test);
char						*test_get_failure_type(t_test *test);

#endif
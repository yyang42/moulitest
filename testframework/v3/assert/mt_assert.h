#ifndef ASSERT_H
# define ASSERT_H

typedef struct				s_assert
{
	char					*name;
	// int						cond_res;
}							t_assert;

t_assert					*assert_create(char *name);
void						assert_exec(t_assert *an_assert, int cond_res);

#endif
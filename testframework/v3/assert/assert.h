#ifndef ASSERT_H
# define ASSERT_H

typedef struct				s_assert
{
	char					*name;

}							t_assert;

t_assert					*assert_create(char *name);

#endif
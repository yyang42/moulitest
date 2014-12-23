#ifndef TEST_H
# define TEST_H

#include <string.h>
#include <stdlib.h>

typedef struct				s_test
{
	char					*name;
	int						is_success;
	int						test_type;
}							t_test;

t_test			*test_create(char *name);

#endif
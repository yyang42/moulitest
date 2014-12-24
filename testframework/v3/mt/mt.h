#ifndef MT_H
# define MT_H
# include <stdio.h>
# include <suite.h>

typedef struct				s_mt
{
	char					*name;
	t_suite					**suites;
}							t_mt;

t_mt			*mt_create(void);
void			mt_add_suite(t_mt *mt,  t_suite *suite);
void			mt_print_suites(t_mt *mt);

#endif

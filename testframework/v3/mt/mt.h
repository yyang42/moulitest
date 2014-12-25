#ifndef MT_H
# define MT_H
# define ffprintf(str) fflush(stdout); fprintf(stdout, str); fflush(stdout);
# include <stdio.h>
# include <suite.h>
# define MAIN_COL_WIDTH 41

typedef struct				s_mt
{
	char					*name;
	t_lst					*suites;
}							t_mt;

t_mt			*mt_create(void);
void			mt_exec(t_mt *mt);

#endif

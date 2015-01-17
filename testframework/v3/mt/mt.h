#ifndef MT_H
# define MT_H
# define ffprintf(str) fflush(stdout); fprintf(stdout, str); fflush(stdout);
# include <stdio.h>
# include <suite.h>
# define MAIN_COL_WIDTH 41
# define DEFAULT_TIMEOUT_UTIME 2 * 1000 * 1000

typedef struct				s_mt
{
	char					*name;
	char					*desc;
	t_lst					*suites;
}							t_mt;

t_mt			*mt_create(char *name);
void			mt_exec(t_mt *mt);
size_t			mt_count_failed_suites(t_mt *mt);
size_t			mt_count_tests(t_mt *mt);
size_t			mt_count_failed_tests(t_mt *mt);

#endif

#include <mt.h>

static void		mt_exec_suites(t_mt *mt)
{
	lst_iter(mt->suites, (void *)suite_exec);
}

static void		mt_print_header(t_mt *mt)
{
	printf("[============ MOULITEST ============]\n");
	(void)mt;
}

static void		mt_print_footer(t_mt *mt)
{
	printf("[=============== END ===============]\n");
	(void)mt;
}

void			mt_exec(t_mt *mt)
{
	mt_print_header(mt);
	mt_exec_suites(mt);
	mt_print_footer(mt);
}

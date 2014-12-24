#include <mt.h>

static void		mt_exec_suites(t_mt *mt)
{
	t_suite	**suites;

	suites = mt->suites;
	while(*suites)
	{
		fprintf(stdout, "-> %s : ", (*suites)->name);
		suite_exec(*suites);
		fprintf(stdout, "\n");
		suites++;
	}	
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

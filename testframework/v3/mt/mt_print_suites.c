#include <mt.h>

void			mt_execute(t_mt *mt)
{
	t_suite	**suites;

	suites = mt->suites;
	while(*suites)
	{
		printf("== suite == : %s\n", (*suites)->name);
		suite_print_tests(*suites);
		suites++;
	}
}

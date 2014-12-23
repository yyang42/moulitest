#include <mt.h>

void			mt_add_suite(t_mt *mt,  t_suite *suite)
{
	t_suite	**suites;

	suites = mt->suites;
	while(*suites)
		suites++;
	*suites = suite;
	++suites;
	*suites = NULL;
}
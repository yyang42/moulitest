#include <mt.h>
#include <fw.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

t_mt			*mt_create(void)
{
	t_mt	*mt;	

	mt = (t_mt *)malloc(sizeof(t_mt));
	mt->suites = (t_suite **)malloc(sizeof(t_suite) * MAX_SUITES);
	mt->suites[0] = NULL;
	return (mt);
}

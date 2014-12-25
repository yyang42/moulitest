#include <mt.h>
#include <fw.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <lst.h>

t_mt			*mt_create(void)
{
	t_mt	*mt;	

	mt = (t_mt *)malloc(sizeof(t_mt));
	mt->suites = lst_init();
	return (mt);
}

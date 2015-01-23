#include <mt.h>
#include <fw.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mt_lst.h>

t_mt			*mt_create(char *name)
{
	t_mt	*mt;	

	mt = (t_mt *)malloc(sizeof(t_mt));
	mt->name = name;
	mt->desc = NULL;
	mt->suites = mt_lst_init();
	return (mt);
}

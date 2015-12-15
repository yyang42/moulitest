#include <mt.h>
#include <fw.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mt_lst.h>

void				mt_del(t_mt *mt)
{
	mt_lst_del(mt->suites, suite_del);
	free(mt);
}

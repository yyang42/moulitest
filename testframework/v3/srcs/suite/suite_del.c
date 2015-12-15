#include <suite.h>

void				suite_del(t_suite *suite)
{
	mt_lst_del(suite->tests, test_del);
	free(suite->name);
	free(suite);
}

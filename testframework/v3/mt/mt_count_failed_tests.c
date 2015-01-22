#include <mt.h>

static int sum_suite_tests(t_mt_lst_elem *elem, int memo)
{
	t_suite *suite;

	suite = elem->data;
	return (suite_count_failed_tests(suite) + memo);
}

size_t		mt_count_failed_tests(t_mt *mt)
{
	return (mt_lst_reducei(mt->suites, sum_suite_tests, 0));
}

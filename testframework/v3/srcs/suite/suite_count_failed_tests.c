#include <suite.h>

size_t		suite_count_failed_tests(t_suite *suite)
{
	return (mt_lst_count(suite->tests, (void *)test_filter_failed));
}

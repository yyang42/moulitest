#include <suite.h>

size_t		suite_count_tests(t_suite *suite)
{
	return (mt_lst_len(suite->tests));
}

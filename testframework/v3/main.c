#include <mt.h>

#define assert(cond) suite_add_test(suite, test_create(#cond, cond))
#define MT_ADD_SUITE(mt, suite_fn) mt_add_suite(mt, suite_create(#suite_fn, suite_fn))

void	suite_01_test_without_opt(t_suite *suite)
{
	assert(1 == 0);
	assert(1 == 1);
	// assert(strcmp("aaa", "bbb") == 0);
}

int main()
{
	t_mt	*mt = mt_create();

	MT_ADD_SUITE(mt, suite_01_test_without_opt);

	mt_execute(mt);
	return(0);
}

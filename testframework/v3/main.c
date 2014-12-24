#include <mt.h>

#define assert(cond) suite_add_test(suite, test_create(#cond, cond))
#define ADD_SUITE(suite_fn) mt_add_suite(mt, suite_create(#suite_fn, suite_fn))

void	suite_01_test_without_opt(t_suite *suite)
{
	assert(1 == 0);
	assert(strcmp("aaa", "bbb") == 0);
}

int main()
{
	t_mt	*mt;
	// t_suite	*suite;

	mt = mt_create();
	ADD_SUITE(suite_01_test_without_opt);

	// suite = suite_create("my suite 1");
	// mt_add_suite(mt, suite);
	// mt_add_suite(mt, suite_create("my suite 2"));
	// suite->fn = &suite_01_test_without_opt;
	// suite->fn(suite);
	// suite_add_test(mt->suites[0], test_create("my tests 1"));
	// suite_add_test(mt->suites[1], test_create("my tests 2"));
	mt_print_suites(mt);
	return(0);
}

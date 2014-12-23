#include <mt.h>

int main()
{
	t_mt	*mt;

	mt = mt_create("my test");
	mt_add_suite(mt, suite_create("my suite 1"));
	mt_add_suite(mt, suite_create("my suite 2"));
	suite_add_test(mt->suites[0], test_create("my tests 1"));
	suite_add_test(mt->suites[1], test_create("my tests 2"));

	mt_print_suites(mt);
	return(0);
}

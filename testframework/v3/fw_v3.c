#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>
#include <mt.h>

#define MAX_SUITES 1000
#define MAX_TESTS_PER_SUITE 1000

// suite
////////////////////////////////////////////////////////////////////////////////

t_test						*test_create(char *name)
{
	t_test	*test;	

	test = (t_test *)malloc(sizeof(t_test));
	test->name = strdup(name);
	return (test);
}
// void						test_exec(t_test test);

// suite
////////////////////////////////////////////////////////////////////////////////

t_suite						*suite_create(char *name);
// void						suite_add_suite(t_suite suite);
// int							suite_is_success(t_suite suite);
// int							suite_success_count(t_suite suite);
// int							suite_fail_count(t_suite suite);
// void						suite_print_result(t_suite suite);
t_suite			*suite_create(char *name)
{
	t_suite	*suite;

	suite = (t_suite *)malloc(sizeof(t_suite));
	suite->name = strdup(name);

	suite->tests = (t_test **)malloc(sizeof(t_test) * MAX_TESTS_PER_SUITE);
	suite->tests[0] = NULL;	// suite->name = strdup(name);
	return (suite);
}
void			suite_add_test(t_suite *suite, t_test	*test)
{
	t_test	**tests;

	tests = suite->tests;
	while(*tests)
		tests++;
	*tests = test;
	++tests;
	*tests = NULL;
}
void			suite_print_tests(t_suite *suite)
{
	t_test	**tests;

	tests = suite->tests;
	while(*tests)
		printf("- test : %s\n", (*tests++)->name);
}

// moulitest
////////////////////////////////////////////////////////////////////////////////

t_mt			*mt_create(char *name)
{
	t_mt	*mt;	

	mt = (t_mt *)malloc(sizeof(t_mt));
	mt->name = strdup(name);
	mt->suites = (t_suite **)malloc(sizeof(t_suite) * MAX_SUITES);
	mt->suites[0] = NULL;
	return (mt);
}

void			mt_add_suite(t_mt *mt,  t_suite *suite)
{
	t_suite	**suites;

	suites = mt->suites;
	while(*suites)
		suites++;
	*suites = suite;
	++suites;
	*suites = NULL;
}
void			mt_print_suites(t_mt *mt)
{
	t_suite	**suites;

	suites = mt->suites;
	while(*suites)
	{
		printf("== suite == : %s\n", (*suites)->name);
		suite_print_tests(*suites);
		suites++;
	}
}

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

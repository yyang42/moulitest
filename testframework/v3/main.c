#include <unistd.h>
#include <string.h>
#include <fw.h>
#include <mt.h>
#include <test.h>
#include <signal.h>

// #define assert(cond) test_assert_prep(test, #cond); test_assert(test, (cond))
// #define MT_ADD_SUITE(mt, suite_fn) lst_push(mt->suites, suite_create(#suite_fn, suite_fn))
// #define SUITE_ADD_TEST(suite, test_fn) lst_push(suite->tests, test_create(#test_fn, test_fn))
// #define MT_ADD_SUITE(mt, name, suite_fn) lst_push(mt->suites, lst_create_elem(mt->suites, suite_create(#name, suite_fn)))
// #define SUITE_ADD_TEST(suite, test_fn) lst_push(suite->tests, lst_create_elem(mt->suites, test_create(#test_fn, test_fn)))

// static test_01_abc(t_suite *suite)
// {
// 	suite->test_str
// }
char cmd[1000];

static void setup(t_suite *suite)
{
	strcpy(cmd, "-l");
	strcat(cmd, "1");
	(void)suite;
}

static void test_fail_int(t_test *test)
{
	assert(1 == 0);
	(void)test;
}

static void test_fail_str(t_test *test)
{
	assert(strcmp("aaa", "bbb") == 0);
	(void)test;
}

static void test_fail_segfaul(t_test *test)
{
	assert(raise(SIGSEGV) == 0);
	(void)test;
}

static void test_fail_buserror(t_test *test)
{
	assert(raise(SIGBUS) == 0);
	(void)test;
}

static void test_success(t_test *test)
{
	assert(1);
	(void)test;
}

static void	suite_01_first(t_suite *suite)
{
	setup(suite);
	SUITE_ADD_TEST(suite, test_fail_int);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_fail_str);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
}

static void	suite_02_second(t_suite *suite)
{
	setup(suite);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_fail_str);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_fail_str);
}


static void	suite_03_third_some_desc(t_suite *suite)
{
	setup(suite);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_success);
}

static void	suite_04_fourth_segv(t_suite *suite)
{
	setup(suite);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_fail_segfaul);
	SUITE_ADD_TEST(suite, test_success);
	SUITE_ADD_TEST(suite, test_fail_buserror);
}

int main()
{
	t_mt	*mt = mt_create();

	MT_ADD_SUITE(mt, 01_first, suite_01_first);
	MT_ADD_SUITE(mt, 02_second, suite_02_second);
	MT_ADD_SUITE(mt, 03_third_some_desc, suite_03_third_some_desc);
	MT_ADD_SUITE(mt, 04_fourth_segv, suite_04_fourth_segv);

	mt_exec(mt);
	return(0);
}

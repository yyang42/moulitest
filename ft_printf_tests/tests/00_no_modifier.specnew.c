#include <fw.h>
#include <test.h>
#include <suite.h>

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

void	suite_00_no_modifier(t_suite *suite)
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

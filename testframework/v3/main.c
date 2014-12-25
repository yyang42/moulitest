#include <unistd.h>
#include <string.h>
#include <mt.h>
#include <test.h>

// #define assert(cond) suite_add_test(suite, test_create(#cond, cond))
#define MT_ADD_SUITE(mt, suite_fn) mt_add_suite(mt, suite_create(#suite_fn, suite_fn))
#define SUITE_ADD_TEST(suite, test_fn) suite_add_test(suite, test_create(#test_fn, test_fn))

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

static void test_01_usr(t_test *test)
{
	// exec(cmd);
	// assert(strcmp(cmd, "-l1") == 0);
	printf("%s\n", "test_01_usr");
	(void)test;
}

static void test_02_usr(t_test *test)
{
	// exec(cmd);
	// assert(1 == 1);
	printf("%s\n", "test_02_usr");
	(void)test;
}
static void test_03_usr(t_test *test)
{
	// exec(cmd);
	// assert(1 == 0);
	printf("%s\n", "test_03_usr");
	(void)test;
}

void	suite_01_opt_l(t_suite *suite)
{
	setup(suite);
	SUITE_ADD_TEST(suite, test_01_usr);
	SUITE_ADD_TEST(suite, test_02_usr);
	SUITE_ADD_TEST(suite, test_03_usr);
	// suite->test_str = "jack";
}

// void	suite_02_opt_R(t_suite *suite)
// {
// 	// suite->test_str = "jack";
// 	assert(1 == 0);
// 	assert(0 == 0);
// 	assert(1 == 0);
// }


int main()
{
	t_mt	*mt = mt_create();

	MT_ADD_SUITE(mt, suite_01_opt_l);
	// MT_ADD_SUITE(mt, suite_02_opt_R);

	// printf("%s\n", mystr);

	mt_exec(mt);
	return(0);
}

#include <mt.h>
#include <unistd.h>
#include <string.h>

#define assert(cond) suite_add_test(suite, test_create(#cond, cond))
#define MT_ADD_SUITE(mt, suite_fn) mt_add_suite(mt, suite_create(#suite_fn, suite_fn))

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

static void test_01_usr(t_suite *suite)
{
	// exec(cmd);
	assert(strcmp(cmd, "-l1") == 0);
}

static void test_02_usr(t_suite *suite)
{
	// exec(cmd);
	assert(1 == 1);
}
static void test_03_usr(t_suite *suite)
{
	// exec(cmd);
	assert(1 == 0);
}

void	suite_01_opt_l(t_suite *suite)
{
	setup(suite);
	test_01_usr(suite);
	test_02_usr(suite);
	test_03_usr(suite);
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

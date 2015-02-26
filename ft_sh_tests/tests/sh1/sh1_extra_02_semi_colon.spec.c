#include <project.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	mt_assert_sh_stdout(test,
		";\n"
		" ; \n"
		"; ;\n"
		";\t \t ;\t; ;\t\t;\t\n"
		"\t;\t \t ;\t\n"
		"env\n"
		"exit\n",
		"grep 'HOME'");
}

void	suite_sh1_extra_02_semi_colon(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}

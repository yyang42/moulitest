#include <project.h>
// #define mt_test_atoi(test_name, tested_str) \
// 	static void test_## test_name(t_test *test) \
// 	{ \
// 		mt_assert(ft_atoi(tested_str) == atoi(tested_str)); \
// 	}

static void simple_test(t_test *test)
{
	char	*actual = fillit_output("tests/00_simple_case_input.fillit");
	char	*expected = get_cmd_out("cat ./tests/00_simple_case_output.fillit");

	printf("==============\n");
	printf(actual);
	printf("==============\n");
	printf(expected);
	mt_assert(strcmp(actual, expected) == 0);
}

void	suite_00_simple_case(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

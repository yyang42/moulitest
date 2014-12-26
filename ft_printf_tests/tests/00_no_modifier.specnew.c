#include <fw.h>
#include <test.h>
#include <suite.h>
#include <stdarg.h>
#include <project.h>

static void test_simple_printf(t_test *test)
{
	// printf("%s\n", ft_printf_to_str("abc"));;
	assert_printf("aaa");
	(void)test;
}

void	suite_00_no_modifier(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_printf);
}

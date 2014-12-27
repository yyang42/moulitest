#include <fw.h>
#include <test.h>
#include <suite.h>
#include <stdarg.h>
#include <project.h>
#include <capture.h>
#include <unistd.h>


void	myprintf(char *str, ...)
{
	va_list vlist;
	char	stab[2000];

	va_start(vlist, str);
	// vprintf(str, va_arg(vlist, char *), va_arg(vlist, char *));
	// fprintf(stderr, "%s\n", va_arg(vlist, char *));
	// fprintf(stderr, "%s\n", va_arg(vlist, char *));
	// for (stab = str; i >= 0; i = va_arg(vlist, int))
	// 	printf("%d ", i);
	va_end(vlist);
	putchar('\n');
}

static void test_simple_printf00(t_test *test)
{
	assert_printf("aaa", NULL);
}

static void test_simple_printf01(t_test *test)
{
	assert_printf("aaa", NULL);
}

static void test_simple_printf02(t_test *test)
{
	assert_printf("a%sc", "b");
}

static void test_simple_printf03(t_test *test)
{
	assert_printf("aaa", NULL);
}

void	suite_00_no_modifier(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_printf00);
	SUITE_ADD_TEST(suite, test_simple_printf01);
	SUITE_ADD_TEST(suite, test_simple_printf02);
	SUITE_ADD_TEST(suite, test_simple_printf03);
}

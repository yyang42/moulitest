#include <fw.h>
#include <test.h>
#include <suite.h>
#include <stdarg.h>
#include <project.h>


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

static void test_simple_printf(t_test *test)
{
	// myprintf("aaa%s%s", "bbb", "ccc");
	assert_printf("aaa\n", NULL);
}

void	suite_00_no_modifier(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_printf);
}

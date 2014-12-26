#include <fw.h>
#include <test.h>
#include <suite.h>
#include <stdarg.h>

static char	*ft_printf_to_str(char *format, ...)
{
	int		out;
	int		p[2];
	char	*buf;
    va_list args;

	buf = malloc(100 * 1000);
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

    va_start(args, format);
    ft_printf(format, args);
    va_end(args);

	dup2(out, 1);
	read(p[0], buf, 100 * 1000);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	return (buf);
}

static void test_simple_printf(t_test *test)
{
	// printf("%s\n", ft_printf_to_str("abc"));;
	assert(strcmp(ft_printf_to_str("aaa"), "aaa") == 0);
	(void)test;
}

void	suite_00_no_modifier(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_printf);
}

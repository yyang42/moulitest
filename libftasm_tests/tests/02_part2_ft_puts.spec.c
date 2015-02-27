#include <project.h>

static void simple_test(t_test *test)
{
	int		ret;
	int		puts_ret1;
	int		puts_ret2;
	int		out;
	int		p[2];
	char	buf[10000];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	puts_ret1 = ft_puts("aaa");
	puts_ret2 = ft_puts(NULL);
	dup2(out, 1);
	ret = read(p[0], buf, 10000);
	buf[ret] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	mt_assert(puts_ret1 > 0);
	mt_assert(puts_ret2 > 0);
	mt_assert(strcmp(buf, "aaa\n(null)\n") == 0);
}

void	suite_02_part2_ft_puts(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

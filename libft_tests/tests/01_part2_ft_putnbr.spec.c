#include <project.h>

static void simple_test(t_test *test)
{
	int		out;
	int		p[2];
	char	buf[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putnbr(0);
	ft_putnbr(1);
	ft_putnbr(-1);
	ft_putnbr(12300);
	ft_putnbr(10203);
	ft_putnbr(-56);
	ft_putnbr(2147483647);
	ft_putnbr(-2147483648);
	dup2(out, 1);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	mt_assert(strcmp(buf, "01-11230010203-562147483647-2147483648") == 0);
}

void	suite_01_part2_ft_putnbr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

#include <project.h>

static void simple_test(t_test *test)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putnbr_fd(0, p[1]);
	ft_putnbr_fd(1, p[1]);
	ft_putnbr_fd(-1, p[1]);
	ft_putnbr_fd(56, p[1]);
	ft_putnbr_fd(-1230, p[1]);
	ft_putnbr_fd(10203, p[1]);
	ft_putnbr_fd(2147483647, p[1]);
	ft_putnbr_fd(-2147483648, p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	mt_assert(strcmp(buf, "01-156-1230102032147483647-2147483648") == 0);
}

void	suite_01_part2_ft_putnbr_fd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

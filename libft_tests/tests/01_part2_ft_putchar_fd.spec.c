#include <project.h>

static void simple_test(t_test *test)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putchar_fd('a', p[1]);
	ft_putchar_fd('b', p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	mt_assert(strcmp(buf, "ab") == 0);
}

void	suite_01_part2_ft_putchar_fd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

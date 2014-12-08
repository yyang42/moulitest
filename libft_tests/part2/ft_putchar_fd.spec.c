#include "project.h"

UT_TEST(ft_putchar_fd)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putchar_fd('a', p[1]);
	ft_putchar_fd('b', p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	UT_ASSERT_EQ(strcmp(buf, "ab"), 0);
}

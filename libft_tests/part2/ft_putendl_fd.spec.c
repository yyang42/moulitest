#include "project.h"

UT_TEST(ft_putendl_fd)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putendl_fd("A QUE KOUKOU", p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	UT_ASSERT_EQ(strcmp(buf, "A QUE KOUKOU\n"), 0);
}

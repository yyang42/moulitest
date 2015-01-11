#include <project.h>

static void simple_test(t_test *test)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putendl_fd("A QUE KOUKOU", p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	mt_assert(strcmp(buf, "A QUE KOUKOU\n") == 0);
}

void	suite_01_part2_ft_putendl_fd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

#include <project.h>

static void simple_test(t_test *test)
{

	int		out;
	int		p[2];
	char	buf[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putendl("aa");
	dup2(out, 1);
	read(p[0], buf, 3);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	mt_assert(strcmp(buf, "aa\n") == 0);
}

void	suite_01_part2_ft_putendl(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

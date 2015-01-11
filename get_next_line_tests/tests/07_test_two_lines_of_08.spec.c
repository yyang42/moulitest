#include <project.h>

static void simple_string(t_test *test)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	
	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefgh\n", 9);
	write(fd, "ijklmnop\n", 9);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "abcdefgh") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "ijklmnop") == 0);
}

void	suite_07_test_two_lines_of_08(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}

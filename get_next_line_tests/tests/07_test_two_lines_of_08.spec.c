#include <project.h>

UT_TEST(07_test_two_lines_of_08)
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
	UT_ASSERT(strequ(line, "abcdefgh"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "ijklmnop"));
}
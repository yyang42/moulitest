#include <project.h>

UT_TEST(08_test_few_lines_of_08)
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
	write(fd, "qrstuvwx\n", 9);
	write(fd, "yzabcdef\n", 9);
	write(fd, "ghijklmn\n", 9);
	write(fd, "opqrstuv\n", 9);
	write(fd, "wxyzabcd\n", 9);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "abcdefgh"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "ijklmnop"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "qrstuvwx"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "yzabcdef"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "ghijklmn"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "opqrstuv"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "wxyzabcd"));
}
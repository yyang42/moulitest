#include <project.h>

static void simple_string(t_test *test)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	write(fd, "ghijklmnopqrstuv\n", 17);
	write(fd, "wxyzabcdefghijkl\n", 17);
	write(fd, "mnopqrstuvwxyzab\n", 17);
	write(fd, "cdefghijklmnopqr\n", 17);
	write(fd, "stuvwxzabcdefghi\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "abcdefghijklmnop") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "qrstuvwxyzabcdef") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "ghijklmnopqrstuv") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "wxyzabcdefghijkl") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "mnopqrstuvwxyzab") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "cdefghijklmnopqr") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "stuvwxzabcdefghi") == 0);
	ret = get_next_line(p[0], &line);
	mt_assert(ret == 0);
}

void	suite_11_test_few_lines_of_16(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}

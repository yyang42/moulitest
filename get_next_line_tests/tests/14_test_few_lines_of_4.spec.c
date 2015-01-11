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
	write(fd, "abcd\n", 5);
	write(fd, "efgh\n", 5);
	write(fd, "ijkl\n", 5);
	write(fd, "mnop\n", 5);
	write(fd, "qrst\n", 5);
	write(fd, "uvwx\n", 5);
	write(fd, "yzab\n", 5);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "abcd") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "efgh") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "ijkl") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "mnop") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "qrst") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "uvwx") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "yzab") == 0);
	ret = get_next_line(p[0], &line);
	mt_assert(ret == 0);
}

void	suite_14_test_few_lines_of_4(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}

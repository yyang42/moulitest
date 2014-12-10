#include <project.h>

UT_TEST(30_bonus_multiple_fd)
{
	char 	*line0;
	int		p0[2];
	int		fd0 = 0;
	int		out0 = dup(fd0);
	pipe(p0);
	dup2(p0[1], fd0);
	write(fd0, "aaa\nbbb\n", 12);
	dup2(out0, fd0);

	char 	*line_fd1;
	int		p_fd1[2];
	int		fd1 = 1;
	int		out_fd1 = dup(fd1);
	pipe(p_fd1);
	dup2(p_fd1[1], fd1);
	write(fd1, "111\n222\n", 12);
	dup2(out_fd1, fd1);

	char 	*line_fd2;
	int		p_fd2[2];
	int		fd2 = 2;
	int		out_fd2 = dup(fd2);
	pipe(p_fd2);
	dup2(p_fd2[1], fd2);
	write(fd2, "www\nzzz\n", 12);
	dup2(out_fd2, fd2);

	char 	*line_fd3;
	int		p_fd3[2];
	int		fd3 = 3;
	int		out_fd3 = dup(fd3);
	pipe(p_fd3);
	dup2(p_fd3[1], fd3);
	write(fd3, "888\n999\n", 12);
	dup2(out_fd3, fd3);

	get_next_line(p0[0], &line0);
	UT_ASSERT(strequ(line0, "aaa"));

	get_next_line(p_fd1[0], &line_fd1);
	UT_ASSERT(strequ(line_fd1, "111"));

	get_next_line(p_fd2[0], &line_fd2);
	UT_ASSERT(strequ(line_fd2, "www"));

	get_next_line(p_fd3[0], &line_fd3);
	UT_ASSERT(strequ(line_fd3, "888"));

	get_next_line(p0[0], &line0);
	UT_ASSERT(strequ(line0, "bbb"));

	get_next_line(p_fd1[0], &line_fd1);
	UT_ASSERT(strequ(line_fd1, "222"));

	get_next_line(p_fd2[0], &line_fd2);
	UT_ASSERT(strequ(line_fd2, "zzz"));

	get_next_line(p_fd3[0], &line_fd3);
	UT_ASSERT(strequ(line_fd3, "999"));
}

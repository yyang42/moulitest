char 	*line;
int		out;
int		p[2];
int		fd;

fd = 11;
out = dup(fd);
pipe(p);

dup2(p[1], fd);
write(fd, "\naaa\nbbb\n", 9);
dup2(out, fd);
close(p[1]);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, ""), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "aaa"), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "bbb"), 0);
get_next_line(p[0], &line);

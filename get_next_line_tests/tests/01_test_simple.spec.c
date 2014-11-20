char 	*line;
int		out;
int		p[2];
int		fd;

fd = 11;
out = dup(fd);
pipe(p);

dup2(p[1], fd);
write(fd, "aaa\nbbb\nccc\nddd\n", 16);
dup2(out, fd);
close(p[1]);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "aaa"), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "bbb"), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "ccc"), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "ddd"), 0);

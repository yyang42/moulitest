char 	*line;
int		out;
int		p[2];
int		fd;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcdefghijklmnop\n", 17);
write(fd, "qrstuvwxyzabcdef\n", 17);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "abcdefghijklmnop"), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "qrstuvwxyzabcdef"), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, ""), 0);
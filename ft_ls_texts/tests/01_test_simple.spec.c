char 	*line;
int		out;
int		p[2];
int		fd;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "\naaa\nbbb\n", 12);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strcmp(line, "") == 0);
get_next_line(p[0], &line);
UT_ASSERT(strcmp(line, "aaa") == 0);
get_next_line(p[0], &line);
UT_ASSERT(strcmp(line, "bbb") == 0);

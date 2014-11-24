char *line;
int		out;
int		p[2];
int		fd;

fd = 1;
out = dup(fd);
pipe(p);
dup2(p[1], fd);
write(fd, "aaa", 3);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "aaa"));

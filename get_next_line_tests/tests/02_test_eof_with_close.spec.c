char *line;
int		out;
int		p[2];

out = dup(1);
pipe(p);
dup2(p[1], 1);
write(1, "aaa", 4);
close(p[1]);
dup2(out, 1);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "aaa"), 0);


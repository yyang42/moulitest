char *line;
int		out;
int		p[2];

line = strdup("===");
out = dup(1);
pipe(p);
dup2(p[1], 1);
write(1, "aaa\nbbb\nccc\n", 12);
dup2(out, 1);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "aaa"), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "bbb"), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "ccc"), 0);

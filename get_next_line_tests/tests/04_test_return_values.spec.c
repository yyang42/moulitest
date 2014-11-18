/* Thank you bwyyoung for pointing out the problem.
 */
char 	*line;
int		out;
int		p[2];
int		fd;
int		gnl_ret;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "aaaaaaaaaaaaaa", 14);
close(p[1]);
dup2(out, fd);

gnl_ret = get_next_line(p[0], &line);
UT_ASSERT_EQ(gnl_ret, 0);
UT_ASSERT(line != NULL);
UT_ASSERT_EQ(strcmp(line, "aaaaaaaaaaaaaa"), 0);

/* get_next_line should return NULL when there is nothing to read. */
gnl_ret = get_next_line(p[0], &line);
UT_ASSERT(line == NULL || *line == '\0');
UT_ASSERT_EQ(gnl_ret, 0);

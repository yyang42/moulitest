system("openssl rand -out 21.txt -base64 $((2**(42/2) * 3/4))");

char *line;
int fd;
int fd2;


fd = open("21.txt", O_RDONLY);
fd2 = open("21.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

while (get_next_line(fd, &line) == 1)
{
    write(fd2, line, strlen(line));
    write(fd2, "\n", 1);
}
close(fd);
close(fd2);

int fd3;
int	diff_file_size;
system("diff 21.txt 21.txt.mine > 21.diff");
fd3 = open("21.diff", O_RDONLY);
diff_file_size = read(fd3, NULL, 10);
close(fd3);

UT_ASSERT(diff_file_size == 0);

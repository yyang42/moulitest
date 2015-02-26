#include <project.h>
#include <fcntl.h>

static void simple_test(t_test *test)
{
	int pids[2];
	char buf[10];
	int saved_stdout;

	saved_stdout = dup(1);
	pipe(pids);
	dup2(pids[1], 1);

	int fd;

	system("echo '12345678912345678' > catout");
	fd = open("catout", O_RDONLY);
	if (fd == -1)
		return ;
	ft_cat(fd);
	read(pids[0], buf, 17);
	dup2(saved_stdout, 1);

	close(fd);
	close(pids[0]);
	close(pids[1]);
	close(saved_stdout);
	system("rm catout");
	mt_assert(memcmp(buf, "12345678912345678", 17) == 0);
}

void	suite_03_part3_ft_cat(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

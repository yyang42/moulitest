#include <project.h>

static void test01(t_test *test)
{
	test->timeout = 5;

	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		len = 50;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while (len--)
		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	if (str)
		write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, str) == 0);
}

void	suite_40_hard_test_medium_string(t_suite *suite)
{
	SUITE_ADD_TEST_TIMEOUT(suite, test01, 5 * 1000000);
}

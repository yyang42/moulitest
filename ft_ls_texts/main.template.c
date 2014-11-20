#include <testframework.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc/malloc.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define MAX_CMD_SIZE 10000

<DEF_BLOCK>

char	ft_ls_path[MAX_CMD_SIZE] = RENDU_PATH"/ft_ls";
char	ls_path[MAX_CMD_SIZE] = "/bin/ls";

char	*get_cmd_out(const char *cmd)
{

	FILE *fp;
	char buf[1035];
	char *out;

	out = malloc(0);

	fp = popen(cmd, "r");

	/* Read the output a line at a time - output it. */
	while (fgets(buf, sizeof(buf)-1, fp) != NULL) {
		out = realloc(out, strlen(out) + strlen(buf) + 1);
		strcat(out, buf);
	}
	pclose(fp);
	return (out);
}

char	*ls(const char *options)
{
	char cmd[MAX_CMD_SIZE];

	bzero(cmd, MAX_CMD_SIZE);
	strcat(cmd, ls_path);
	strcat(cmd, " ");
	strcat(cmd, options);
	return get_cmd_out(cmd);
}

char	*ft_ls(const char *options)
{
	char cmd[MAX_CMD_SIZE];

	bzero(cmd, MAX_CMD_SIZE);
	strcat(cmd, ft_ls_path);
	strcat(cmd, " ");
	strcat(cmd, options);
	return get_cmd_out(cmd);
}

<TEST_DEF_BLOCK>

int	main(void)
{
<MAIN_TEST_BLOCK>

	UT_RUN_ALL_TESTS();
	return (0);
}

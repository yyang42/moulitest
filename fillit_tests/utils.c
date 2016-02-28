#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <project.h>

#define MAX_CMD_SIZE 10000
// char	fillit_path[MAX_CMD_SIZE] = RENDU_PATH"/fillit";
char	fillit_path[MAX_CMD_SIZE] = "cat -e";

char	*get_cmd_out(const char *cmd)
{
	FILE *fp;
	char buf[1035];
	char *out;

	out = malloc(1);
	*out = '\0';

	fp = popen(cmd, "r");

	/* Read the output a line at a time - output it. */
	while (fgets(buf, sizeof(buf)-1, fp) != NULL) {
		out = realloc(out, strlen(out) + strlen(buf) + 1);
		strcat(out, buf);
	}
	pclose(fp);
	return (out);
}

char	*fillit_output(const char *options)
{
	char cmd[MAX_CMD_SIZE];

	bzero(cmd, MAX_CMD_SIZE);
	strcat(cmd, fillit_path);
	strcat(cmd, " ");
	strcat(cmd, options);
	// strcat(cmd, " 2>&1");
	return get_cmd_out(cmd);
}

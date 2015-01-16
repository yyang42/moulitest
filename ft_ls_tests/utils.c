#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <project.h>

#define MAX_CMD_SIZE 10000
#define SANDBOX_PATH "./sandbox"

int		debug = 0;

char	ft_ls_path[MAX_CMD_SIZE] = RENDU_PATH"/ft_ls";
char	ls_path[MAX_CMD_SIZE] = "/bin/ls";

char *re_replace(char *str, char *pattern, char *replacement)
{
	int ret = 0;
	int cnt = 0;
	int offset = 0;
	char temp[1000000];
	char *output;
	bzero(temp, 1000000);
	regex_t reg;
	regmatch_t pm;
	regcomp(&reg, pattern, REG_EXTENDED); /* REG_ICASE */
	while(ret == 0) {
		ret = regexec(&reg, str + offset, 1, &pm, 0);
		if (ret != 0)
			break;
		strncat(temp, str + offset, pm.rm_so);
		strcat(temp, replacement);
		offset += pm.rm_eo;
		cnt++;
	}
	strcat(temp, str + offset);
	output = strdup(temp);
	return (output);
}

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

char	*sandbox_cmd(const char *cmd)
{
	char full_cmd[MAX_CMD_SIZE];

	bzero(full_cmd, MAX_CMD_SIZE);
	strcat(full_cmd, "cd "SANDBOX_PATH);
	strcat(full_cmd, " && ");
	strcat(full_cmd, cmd);
	if(debug)
		strcat(full_cmd, " 1>&2");
	return get_cmd_out(full_cmd);
}

void	reset_sandbox()
{
	get_cmd_out("chmod -R 777 ./");
	get_cmd_out("rm -rf ./sandbox");
	get_cmd_out("mkdir ./sandbox ");
}

char	*ft_ls(const char *options)
{
	char cmd[MAX_CMD_SIZE];

	bzero(cmd, MAX_CMD_SIZE);
	strcat(cmd, "cd "SANDBOX_PATH);
	strcat(cmd, " && ");
	strcat(cmd, ft_ls_path);
	strcat(cmd, " ");
	strcat(cmd, options);
	strcat(cmd, " 2>&1");
	return get_cmd_out(cmd);
}

char	*ls(const char *options)
{
	char cmd[MAX_CMD_SIZE];

	bzero(cmd, MAX_CMD_SIZE);
	strcat(cmd, "cd "SANDBOX_PATH);
	strcat(cmd, " && ");
	strcat(cmd, ls_path);
	strcat(cmd, " ");
	strcat(cmd, options);
	strcat(cmd, " 2>&1");

	return get_cmd_out(cmd);
}


char	*ls_err(const char *options)
{
	char cmd[MAX_CMD_SIZE];

	bzero(cmd, MAX_CMD_SIZE);
	strcat(cmd, "cd "SANDBOX_PATH);
	strcat(cmd, " && ");
	strcat(cmd, ls_path);
	strcat(cmd, " ");
	strcat(cmd, options);
	strcat(cmd, " 2>&1 1>/dev/null");
	return get_cmd_out(cmd);
}

char	*ft_ls_err(const char *options)
{
	char cmd[MAX_CMD_SIZE];

	bzero(cmd, MAX_CMD_SIZE);
	strcat(cmd, "cd "SANDBOX_PATH);
	strcat(cmd, " && ");
	strcat(cmd, ft_ls_path);
	strcat(cmd, " ");
	strcat(cmd, options);
	strcat(cmd, " 2>&1 1>/dev/null");
	return get_cmd_out(cmd);
}

char *strip_illegal_opt_err(char *str)
{
	str = re_replace(str, "^.*ls: ", "XXXXls: ");
	str = re_replace(str, "usage: (ft_)?ls", "usage: XXXX");
	str = re_replace(str, "\\[-[^]]+\\] ", "[XXXX] ");
	return (str);
}

char *strip_no_such_file_or_dir(char *str)
{
	str = re_replace(str, "[^\n]*ls: ", "XXXXls: ");
	str = re_replace(str, "fts_open", "open");
	return (str);
}

void print_ls_debug(const char *cmd)
{
	printf("\n=====  ls  ========\n");
	printf(ls(cmd));
	printf("===== ft_ls =======\n");
	printf(ft_ls(cmd));
	printf("==================\n");
}

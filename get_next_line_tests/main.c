#include <testframework.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc/malloc.h>
#include <ctype.h>
#include <math.h>
#include <get_next_line.h>
#include <stdio.h>
#include <fcntl.h>
#include <regex.h>

<DEF_BLOCK>

<DEF_BLOCK>

#define FT_LS_PATH RENDU_PATH"/ft_ls"

char	*get_cmd_out(const char *cmd)
{

	FILE *fp;
	char path[1035];
	char *out;

	out = malloc(0);

	fp = popen(cmd, "r");

	/* Read the output a line at a time - output it. */
	while (fgets(path, sizeof(path)-1, fp) != NULL) {
		out = realloc(out, strlen(out) + strlen(path) + 1);
		strcat(out, path);
	}
	pclose(fp);
	printf("%s", out);

}

<TEST_DEF_BLOCK>

int	main(void)
{
<MAIN_TEST_BLOCK>

	UT_RUN_ALL_TESTS();
	return (0);
}

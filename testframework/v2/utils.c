#include <testframework.h>
#include <string.h>

int	strequ(const char *s1, const char *s2)
{
	return (s1 && s2 && strcmp(s1, s2) == 0);
}

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

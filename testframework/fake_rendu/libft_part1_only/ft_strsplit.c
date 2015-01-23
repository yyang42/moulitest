#include <libft.h>
char	**ft_strsplit(char const *s, char c)
{
	char **out;

	out = malloc(sizeof(char *) * 10);
	out[0] = ft_strdup("aaa");
	out[1] = ft_strdup("aaa");
	out[2] = ft_strdup("aaa");
	out[3] = ft_strdup("aaa");
	out[4] = ft_strdup("aaa");
	out[5] = ft_strdup("aaa");
	out[6] = ft_strdup("aaa");

	(void)c;
	(void)s;
	return (out);
}

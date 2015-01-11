#include <fw.h>
#include <libft.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __gnu_linux__
# include <malloc.h>
#else
# include <malloc/malloc.h>
#endif

#include <ctype.h>
#include <math.h>

void	it_test(char *c)
{
	*c = *c + 1;
}

void	iti_test(unsigned int i, char *c)
{
	*c = *c + i;
}

char	map_test(char c)
{
	return (c + 1);
}

char	mapi_test(unsigned int i, char c)
{
	return (c + i);
}

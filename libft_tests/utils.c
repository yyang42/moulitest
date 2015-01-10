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

int		____diddel;

#ifdef BONUS
void	del_test(void *data, size_t i)
{
	(void)data;
	(void)i;
	____diddel++;
}

void	lstiter_test(t_list *ppp)
{
	ppp->content_size = 42;
}

t_list	*lstmap_test(t_list *list)
{
	t_list	*l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = malloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}
#endif

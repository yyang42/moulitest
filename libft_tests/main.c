#include <testframework.h>
#include "libft.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc/malloc.h>
#include <ctype.h>
#include <math.h>

#ifdef PART1

#define	TEST_ft_memset
#define	TEST_ft_bzero
#define	TEST_ft_memcpy
#define	TEST_ft_memccpy
#define	TEST_ft_memmove
#define	TEST_ft_memchr
#define	TEST_ft_memcmp
#define	TEST_ft_strlen
#define	TEST_ft_strdup
#define	TEST_ft_strcpy
#define	TEST_ft_strncpy
#define	TEST_ft_strcat
#define	TEST_ft_strncat
#define	TEST_ft_strlcat
#define	TEST_ft_strchr
#define	TEST_ft_strrchr
#define	TEST_ft_strstr
#define	TEST_ft_strnstr
#define	TEST_ft_strcmp
#define	TEST_ft_strncmp
#define	TEST_ft_atoi
#define	TEST_ft_isalpha
#define	TEST_ft_isdigit
#define	TEST_ft_isalnum
#define	TEST_ft_isascii
#define	TEST_ft_isprint
#define	TEST_ft_toupper
#define	TEST_ft_tolower

#endif

#ifdef PART2

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

#define TEST_ft_memalloc
#define TEST_ft_memdel
#define TEST_ft_strnew
#define TEST_ft_strdel
#define TEST_ft_strclr
#define TEST_ft_striter
#define TEST_ft_striteri
#define TEST_ft_strmap
#define TEST_ft_strmapi
#define TEST_ft_strequ
#define TEST_ft_strnequ
#define TEST_ft_strsub
#define TEST_ft_strjoin
#define TEST_ft_strtrim
#define TEST_ft_strsplit
#define TEST_ft_itoa
#define TEST_ft_putchar
#define TEST_ft_putstr
#define TEST_ft_putendl
#define TEST_ft_putnbr
#define TEST_ft_putchar_fd
#define TEST_ft_putstr_fd
#define TEST_ft_putendl_fd
#define TEST_ft_putnbr_fd

#endif

#ifdef BONUS

int		____diddel;

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

#define TEST_ft_lstnew
#define TEST_ft_lstdelone
#define TEST_ft_lstdel
#define TEST_ft_lstadd
#define TEST_ft_lstiter
#define TEST_ft_lstmap
#endif

<TEST_DEF_BLOCK>

int	main(void)
{
<MAIN_TEST_BLOCK>
	UT_RUN_ALL_TESTS();
	return (0);
}

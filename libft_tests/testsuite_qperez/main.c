/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_QuentinPerez.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:43:06 by student@42        #+#    #+#             */
/*   Updated: 2014/11/09 11:24:51 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *
 *	Salut la nouvelle promo merci de lire README.md et bon courage tout le monde
 *
 *	https://github.com/QuentinPerez
 *	https://github.com/mfontain
 *	https://github.com/alex8092
 *	https://github.com/gabtoubl
 *	https://github.com/soyel
 *	https://github.com/stherman
 *
 */

/*
** author : qperez
** HardCore + strtrim + Fixes: mfontain
** Fixes strsplit, strequ: gabtoubl
** Fixes strsplit, strjoin, strsub, strtrim, itoa, strequ, strnequ: stherman
**
** Any segfault ? Probably caused by a NULL test. ex : ft_memset(NULL, 0, 0);
*/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include <libft.h> /* compile with -I./ */

#define D_ERROR	{ printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__); return (0); }
#define D_ADD_HCTEST(name)	uf_add_test(test, "\033[33m"#name"\033[0m", uf_test_##name);
#define D_ADD_TEST(name)	uf_add_test(test, #name, uf_test_##name);
#define D_TEST	60
#define RANDT	512
#define LONG	10000

int	uf_test_strtrim(void);
int	uf_test_strsplit(void);
int	uf_test_strjoin(void);
int	uf_test_strsub(void);
int	uf_test_itoa(void);
int	uf_test_strnequ(void);
int	uf_test_strequ(void);
int	uf_test_strmapi(void);
int	uf_test_strmap(void);
int	uf_test_striteri(void);
int	uf_test_striter(void);
int	uf_test_strclr(void);
int	uf_test_strdel(void);
int	uf_test_strnew(void);
int	uf_test_memalloc_and_del(void);
int	uf_test_tolower(void);
int	uf_test_toupper(void);
int	uf_test_isprint(void);
int	uf_test_isascii(void);
int	uf_test_isalnum(void);
int	uf_test_isdigit(void);
int	uf_test_isalpha(void);
int	uf_test_atoi(void);
int	uf_test_strncmp(void);
int	uf_test_strcmp(void);
int	uf_test_strnstr(void);
int	uf_test_strstr(void);
int	uf_test_strrchr(void);
int	uf_test_strchr(void);
int	uf_test_strlcat(void);
int	uf_test_strncat(void);
int	uf_test_strcat(void);
int	uf_test_strncpy(void);
int	uf_test_strcpy(void);
int	uf_test_strdup(void);
int	uf_test_strlen(void);
int	uf_test_memmove(void);
int	uf_test_memchr(void);
int	uf_test_memcmp(void);
int	uf_test_memccpy(void);
int	uf_test_memcpy(void);
int	uf_test_memset(void);
int	uf_test_bzero(void);
int	uf_test_lstnew(void);
int	uf_test_lstdelone(void);
int	uf_test_lstdel(void);
int	uf_test_lstadd(void);
int	uf_test_lstiter(void);
int uf_test_lstmap(void);

typedef struct	s_test
{
	const char	*name;
	int			(*funct)(void);
	bool		set;
}				t_test;

void				uf_add_test(t_test *test, const char *name, int (*funct)(void))
{
	static int		i = 0;

	test[i].name = name;
	test[i].funct = funct;
	test[i].set = true;
	test[i + 1].set = false;
	i = i + 1;
}


int					main(int argc, const char **argv)
{
	int				i;
	t_test			test[D_TEST];

	srand(time(NULL));
	printf("[\033[33mYellow Tests\033[0m] are Hardcore\n");
	i = 0;
	memset(test, 0, D_TEST);
/*
 * Si vous n'avez pas la fonction il suffit de mettre en commentaire
 */
/*
 * Example : vous n'avez pas memset vous commentez
 * // #define D_MEMSET
 * // D_ADD_TEST(...)
 */
#define	D_MEMSET
	D_ADD_HCTEST(memset);
#define	D_BZERO
	D_ADD_HCTEST(bzero);
#define	D_MEMCPY
	D_ADD_HCTEST(memcpy);
#define	D_MEMCCPY
	D_ADD_HCTEST(memccpy);
#define	D_MEMMOVE
	D_ADD_HCTEST(memmove);
#define	D_MEMCHR
	D_ADD_HCTEST(memchr);
#define	D_MEMCMP
	D_ADD_HCTEST(memcmp);
#define	D_STRLEN
	D_ADD_TEST(strlen);
#define	D_STRDUP
	D_ADD_TEST(strdup);
#define	D_STRCPY
	D_ADD_HCTEST(strcpy);
#define	D_STRNCPY
	D_ADD_HCTEST(strncpy);
#define	D_STRCAT
	D_ADD_TEST(strcat);
#define	D_STRNCAT
	D_ADD_TEST(strncat);
#define	D_STRLCAT
	D_ADD_TEST(strlcat);
#define	D_STRCHR
	D_ADD_TEST(strchr);
#define	D_STRRCHR
	D_ADD_TEST(strrchr);
#define	D_STRSTR
	D_ADD_TEST(strstr);
#define	D_STRNSTR
	D_ADD_TEST(strnstr);
#define	D_STRCMP
	D_ADD_TEST(strcmp);
#define	D_STRNCMP
	D_ADD_TEST(strncmp);
#define	D_ATOI
	D_ADD_HCTEST(atoi);
#define	D_ISALPHA
	D_ADD_HCTEST(isalpha);
#define	D_ISDIGIT
	D_ADD_HCTEST(isdigit);
#define	D_ISALNUM
	D_ADD_HCTEST(isalnum);
#define	D_ISASCII
	D_ADD_HCTEST(isascii);
#define	D_ISPRINT
	D_ADD_HCTEST(isprint);
#define	D_TOUPPER
	D_ADD_HCTEST(toupper);
#define	D_TOLOWER
	D_ADD_HCTEST(tolower);
#define	D_MEMALLOC_AND_DEL
	D_ADD_TEST(memalloc_and_del);
#define	D_STRNEW
	D_ADD_TEST(strnew);
#define	D_STRDEL
	D_ADD_TEST(strdel);
#define	D_STRCLR
	D_ADD_TEST(strclr);
#define	D_STRITER
	D_ADD_TEST(striter);
#define	D_STRITERI
	D_ADD_TEST(striteri);
#define	D_STRMAP
	D_ADD_TEST(strmap);
#define	D_STRMAPI
	D_ADD_TEST(strmapi);
#define	D_STREQU
	D_ADD_TEST(strequ);
#define	D_STRNEQU
	D_ADD_TEST(strnequ);
#define	D_STRSUB
	D_ADD_TEST(strsub);
#define	D_STRJOIN
	D_ADD_TEST(strjoin);
#define	D_STRSPLIT
	D_ADD_TEST(strsplit);
#define	D_ITOA
	D_ADD_TEST(itoa);
#define	D_STRTRIM
	D_ADD_TEST(strtrim);
#define	D_LSTNEW
	D_ADD_TEST(lstnew);
#define	D_LSTDELONE
	D_ADD_TEST(lstdelone);
#define	D_LSTDEL
	D_ADD_TEST(lstdel);
#define	D_LSTADD
	D_ADD_TEST(lstadd);
#define	D_LSTITER
	D_ADD_TEST(lstiter);
#define D_LSTMAP
	D_ADD_TEST(lstmap);
	while (test[i].set == true)
	{
		printf("Test [%s] : ", test[i].name);
		if (test[i].funct() == 0)
			printf("\033[31mFAIL\033[0m\n");
		else
			printf("\033[32mOK\033[0m\n");
		i = i + 1;
	}
	(void)argc;
	(void)argv;
	return (0);
}

void	uf_del_callback(void *d, size_t s)
{
	free(d);
	(void)s;
}

/*
** Thx pmotte for the test
*/

#ifdef  D_LSTMAP

t_list		*uf_testmap(t_list *elem)
{
	t_list	*new;
	char	*content;
	int		i;

	content = ft_strdup((char *)(elem->content));
	i = 0;
	while (i < (int)ft_strlen(content))
	{
		content[i] += 1;
		++i;
	}
	new = ft_lstnew((void const *) content, 5);
	free(content);
	return (new);
}

int					uf_test_lstmap(void)
{
    t_list			*lst_initial;
    t_list			*lst;
    char			*content;
    t_list			*(*f)(t_list *);

	content = "toto";
	lst_initial = ft_lstnew((void const *) content, 5);
	content = "tata";
	lst_initial->next = ft_lstnew((void const *) content, 5);
	content = "tutu";
	lst_initial->next->next = ft_lstnew((void const *) content, 5);
	f = &uf_testmap;
	lst = ft_lstmap(lst_initial, f);
	if (!strcmp((const char *) lst->content, (const char *) lst_initial->content) || strcmp((const char *) lst->content, "upup"))
        D_ERROR;
    if (!strcmp((const char *) lst->next->content, (const char *) lst_initial->next->content) || strcmp((const char *) lst->next->content, "ubub"))
        D_ERROR;
    if (!strcmp((const char *) lst->next->next->content, (const char *) lst_initial->next->next->content) || strcmp((const char *) lst->next->next->content, "uvuv"))
        D_ERROR;
    return (1);
}
#endif

#ifdef	D_LSTITER
void	uf_iter_callback(t_list *v)
{
	*(size_t*)v->content = *(size_t*)v->content + 1;
}

int					uf_test_lstiter(void)
{
	t_list	*begin;
	size_t	v;
	size_t	w;

	v = 1;
	w = 2;
	begin = ft_lstnew(&v, sizeof(size_t));
	begin->next = ft_lstnew(&w, sizeof(size_t));
	ft_lstiter(begin, uf_iter_callback);
	if (*(size_t*)begin->content != 2)
		D_ERROR;
	if (*(size_t*)begin->next->content != 3)
		D_ERROR;
	free(begin->next);
	free(begin);
	return (1);
}
#endif

#ifdef D_LSTADD
int					uf_test_lstadd(void)
{
	t_list	*begin;
	t_list	*add;
	t_list	*tmp;
	size_t	v;

	v = 1;
	begin = ft_lstnew(&v, sizeof(size_t));
	tmp = begin;
	add = ft_lstnew(&v, sizeof(size_t));
	ft_lstadd(&begin, add);
	if (begin != add)
		D_ERROR;
	if (begin->next != tmp)
		D_ERROR;
	free(begin->next);
	free(begin);
	return (1);
}
#endif

#ifdef	D_LSTDELONE
int					uf_test_lstdelone(void)
{
	t_list	*begin;
	size_t	v;

	v = 1;
	begin = ft_lstnew(&v, sizeof(void *));
	begin->next = ft_lstnew(&v, sizeof(void *));
	begin->next->next = ft_lstnew(&v, sizeof(void *));
	ft_lstdelone(&begin->next->next, uf_del_callback);
	if (begin->next->next != NULL)
		D_ERROR;
	ft_lstdelone(&begin->next, uf_del_callback);
	if (begin->next != NULL)
		D_ERROR;
	ft_lstdelone(&begin, uf_del_callback);
	if (begin != NULL)
		D_ERROR;
	return (1);
}
#endif

#ifdef	D_LSTDEL
int					uf_test_lstdel(void)
{
	t_list	*begin;
	size_t	v;

	v = 1;
	begin = ft_lstnew(&v, sizeof(void *));
	begin->next = ft_lstnew(&v, sizeof(void *));
	begin->next->next = ft_lstnew(&v, sizeof(void *));
	ft_lstdel(&begin, uf_del_callback);
	if (begin != NULL)
		D_ERROR;
	return (1);
}
#endif

#ifdef	D_LSTNEW
int					uf_test_lstnew(void)
{
	t_list	*begin;
	size_t	v;

	v = 1;
	begin = ft_lstnew(NULL, 36);
	if (begin != 0 && (begin->content_size != 0 || begin->content != NULL))
		D_ERROR;
	free(begin);
	begin = ft_lstnew(&v, sizeof(size_t));
	if (begin != NULL)
	{
		if (&v == begin->content)
			D_ERROR;
		if (*(size_t*)begin->content != 1)
			D_ERROR;
		if (begin->content_size != sizeof(size_t))
			D_ERROR;
		if (begin->next != 0)
			D_ERROR;
	}
	free(begin);
	return (1);
}
#endif

int					uf_free_tab(void **tab)
{
	unsigned int	i;

	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i = i + 1;
	}
	free(tab);
	return (1);
}

#ifdef	D_STRTRIM
int					uf_test_strtrim(void)
{
	char			str[] = "  \t    \t\nBon\t \njour\t\n  \n     ";
	char			str2[] = "Bonjour";
	char			str3[] = "  \t\t\t   ";
	char			*r;

	ft_strtrim(NULL);
	r = ft_strtrim(str);
	if (strcmp(r, "Bon\t \njour"))
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"  \t    \t\nBon\t \njour\t\n  \n     \").\nExpected ret = \"Bon\t \njour\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, r);
		free(r);
		return (0);
	}
	free(r);
	r = ft_strtrim(str2);
    if (strcmp(r, "Bonjour") || (str2 == r))
    {
        printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"Bonjour\").\nExpected ret = \"Bonjour\" and differents pointers\
			   but have ret = \"%s\" and our: %p / your: %p\033[0m\n", __LINE__ - 2, __func__, r, str2, r);
		free(r);
        return (0);
    }
    free(r);
	r = ft_strtrim(str3);
    if (strcmp(r, "") || (str3 == r))
    {
        printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"  \t\t\t  \").\nExpected ret = \"\" and different\
s pointers but have ret = \"%s\" and our: %p / your: %p\033[0m\n", __LINE__ - 2, __func__, r, str3, r);
		free(r);
        return (0);
    }
    free(r);
	return (1);
}
#endif

#ifdef	D_STRSPLIT
int					uf_test_strsplit(void)
{
	char			**ret;

	ft_strsplit(NULL, 0);
	ft_strsplit(NULL, 'a');
	ret = ft_strsplit("", '*');
	if (ret == NULL || ret[0] != NULL)
	{
		printf("Error Line %d, Funct %s : \
			   \nYour function has return NULL or the first pointer in your tab is NULL\n", __LINE__ - 2, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	uf_free_tab((void **)ret);
	ret = ft_strsplit("*********", '*');
	if (ret == NULL || ret[0] != NULL)
	{
		printf("Error Line %d, Funct %s : \
			   \nYour function has return NULL or the first pointer in your tab is NULL\n", __LINE__ - 2, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \nUnable to free your tab in first test\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("hello", '*');
	if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"hello\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
			   but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in second test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("*hello", '*');
	if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hello\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
			   but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in third test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("*hello*", '*');
	if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hello*\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
			   but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in third test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("*hel*lo*", '*');
	if (ret[2] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel*lo*\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\" and tab[2] = NULL \
			   but have tab[0] = \"%s\", tab[1] = \"%s\" and tab[2] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in fourth test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("*hel*lo*f", '*');
	if (ret[3] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0 &&
		strcmp(ret[2], "f") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel*lo*f\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\", tab[2] = \"f\" and tab[3] = NULL \
			   but have tab[0] = \"%s\", tab[1] = \"%s\", tab[2] = \"%s\" and tab[3] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2], ret[3]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in fifth test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("g*hel*lo*f", '*');
	if (ret[4] != NULL && strcmp(ret[0], "g") != 0 && strcmp(ret[1], "hel") != 0 &&
		strcmp(ret[2], "lo") != 0 && strcmp(ret[3], "f") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"g*hel*lo*f\", '*').\nExpected tab[0] = \"g\", tab[1] = \"hel\", tab[2] = \"lo\", tab[3] = \"f\" and tab[4] = NULL \
			   but have tab[0] = \"%s\", tab[1] = \"%s\", tab[2] = \"%s\", tab[3] = \"%s\" and tab[4] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2], ret[3], ret[4]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in sixth test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("***hel****lo**", '*');
	if (ret[2] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel****lo*\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\" and tab[2] = NULL \
			   but have tab[0] = \"%s\", tab[1] = \"%s\" and tab[2] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in seventh test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	return (1);
}
#endif

#ifdef	D_STRJOIN
int				uf_test_strjoin(void)
{
	char		*ret;

	ft_strjoin(NULL, NULL);
	ft_strjoin(NULL, "");
	ft_strjoin("", NULL);
	ret = ft_strjoin("Hello ", "boys");
	if (strcmp(ret, "Hello boys") != 0)
	{
		D_ERROR
		free(ret);
		return (0);
	}
	free(ret);
	ret = ft_strjoin("", "boys");
    if (strcmp(ret, "boys") != 0)
    {
		D_ERROR
        free(ret);
        return (0);
    }
    free(ret);
	ret = ft_strjoin("Hello ", "");
    if (strcmp(ret, "Hello ") != 0)
    {
		D_ERROR
        free(ret);
        return (0);
    }
    free(ret);
	ret = ft_strjoin("", "");
    if (strcmp(ret, "") != 0)
    {
		D_ERROR
        free(ret);
        return (0);
    }
    free(ret);
	return (1);
}
#endif

#ifdef	D_STRSUB
int				uf_test_strsub(void)
{
	char		*ret;
	char		str[] = "*Hello*";

	ft_strsub(NULL, 0, 0);
	ft_strsub(NULL, 1, 0);
	ft_strsub(NULL, 1, 1);
	ft_strsub(NULL, 0, 1);
	ret = ft_strsub(str, 1, 5);
	if (strcmp(ret, "Hello") != 0)
	{
		D_ERROR
		return (0);
	}
	ret = ft_strsub(str, 3, 1);
    if (strcmp(ret, "l") != 0)
    {
		D_ERROR
        return (0);
    }
	return (1);
}
#endif

void			uf_striteri_callback(unsigned int i, char *s)
{
	*s = *s + i;
}

void			uf_striter_callback(char *s)
{
	*s = *s + 1;
}

char			uf_strmap_callback(char s)
{
	return (s + 1);
}

char			uf_strmapi_callback(unsigned int i, char s)
{
	return (s + i);
}

#ifdef	D_ITOA
int				uf_test_itoa(void)
{
	char		*ret;
	if (strcmp(ret = ft_itoa(0), "0") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_itoa(0).\nExpected ret = \"0\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(-123), "-123") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_itoa(-123).\nExpected ret = \"-123\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(123), "123") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_itoa(123).\nExpected ret = \"123\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(-2147483648), "-2147483648") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_itoa(-2147483648).\nExpected ret = \"-2147483648\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(2147483647), "2147483647") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_itoa(2147483647).\nExpected ret = \"2147483647\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	return (1);
}
#endif

#ifdef	D_STRNEQU
int				uf_test_strnequ(void)
{
	int			ret;

	ft_strnequ(NULL, NULL, 0);
	ft_strnequ(NULL, NULL, 1);
	ft_strnequ(NULL, "", 1);
	ft_strnequ("", NULL, 1);
	ret = 0;
	if ((ret = ft_strnequ("abc", "abc", 2)) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"abc\", \"abc\", 2).\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strnequ("cba", "abc", 2)) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"cba\", \"abc\", 2).\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strnequ("abc", "cba", 2)) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"abc\", \"cba\", 2).\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strnequ("abc", "abd", 2)) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"abc\", \"abd\", 2).\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strnequ("", "", 3)) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"\", \"\", 3).\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	return (1);
}
#endif

#ifdef	D_STREQU
int				uf_test_strequ(void)
{
	int			ret;
	char		*str;

	ft_strequ(NULL, NULL);
	ft_strequ("", NULL);
	ft_strequ(NULL, "");
	ret = 0;
	str = strdup("abc"); /* FIX un faux OK si l'user a mis "if s1 == s2 return 1;" */
	if ((ret = ft_strequ(str, "abc")) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abc\", \"abc\").\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(str);
		return (0);
	}
	free(str);
	if ((ret = ft_strequ("cba", "abc")) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"cba\", \"abc\").\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strequ("abc", "cba")) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abc\", \"cba\").\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strequ("", "")) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"\", \"\").\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strequ("abc", "abcd")) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abc\", \"abcd\").\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strequ("abcd", "abc")) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abcd\", \"abc\").\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	return (1);
}
#endif

#ifdef	D_STRMAPI
int				uf_test_strmapi(void)
{
	char		str[] = "Hello";
	char		empty[] = "";
	char		*ret;

	ft_strmapi(NULL, NULL);
	ft_strmapi(empty, NULL);
	ret = ft_strmapi(str, uf_strmapi_callback);
	if (strcmp(ret, "Hfnos") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	return (1);
}
#endif

#ifdef	D_STRMAP
int				uf_test_strmap(void)
{
	char		str[] = "Hello";
	char		*ret;

	ft_strmap(NULL, NULL);
	ft_strmap("", NULL);
	ret = ft_strmap(str, uf_strmap_callback);
	if (strcmp(ret, "Ifmmp") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	return (1);
}
#endif

#ifdef	D_STRITERI
int				uf_test_striteri(void)
{
	char		str[] = "Hello";

	ft_striteri(NULL, NULL);
	ft_striteri(str, NULL);
	ft_striteri(str, uf_striteri_callback);
	if (strcmp(str, "Hfnos") != 0)
		D_ERROR
	return (1);
}
#endif

#ifdef	D_STRITER
int				uf_test_striter(void)
{
	char		str[] = "Hello";

	ft_striter(NULL, NULL);
	ft_striter(str, NULL);
	ft_striter(str, uf_striter_callback);
	if (strcmp(str, "Ifmmp") != 0)
		D_ERROR
	return (1);
}
#endif

#ifdef	D_STRCLR
int				uf_test_strclr(void)
{
	int			i;
	char		str[] = "Hello";

	i = 0;
	ft_strclr(NULL);
	ft_strclr(str);
	while (i < 6)
	{
		if (str[i] != '\0')
			D_ERROR
	i = i + 1;
	}
	return (1);
}
#endif

#ifdef	D_STRDEL
int				uf_test_strdel(void)
{
	char		*ret;

	ft_strdel(NULL);
	ret = ft_strnew(4);
	ft_strdel(&ret);
	if (ret != NULL)
		D_ERROR
	ret = ft_strnew(0);
	ft_strdel(&ret);
	if (ret != NULL)
		D_ERROR
	return (1);
}
#endif

#ifdef	D_STRNEW
int				uf_test_strnew(void)
{
	char		*ret;
	int			i;

	i = 0;
	ret = ft_strnew(4);
	if (ret != NULL)
	{
		while (i < 5)
		{
			if (ret[i] != '\0')
				D_ERROR
			i = i + 1;
		}
	}
	return (1);
}
#endif

#ifdef	D_MEMALLOC_AND_DEL
int				uf_test_memalloc_and_del(void)
{
	void		*ret;

	ret = ft_memalloc(4);
	ft_memdel(&ret);
	if (ret != NULL)
		D_ERROR
	return (1);
}
#endif

#ifdef	D_TOLOWER
int				uf_test_tolower(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (tolower(i) != ft_tolower(i))
			D_ERROR
		i = i + 1;
	}
	return (1);
}
#endif

#ifdef	D_TOUPPER
int				uf_test_toupper(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (toupper(i) != ft_toupper(i))
			D_ERROR
		i = i + 1;
	}
	return (1);
}
#endif

#ifdef	D_ISPRINT
int				uf_test_isprint(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isprint(i) != ft_isprint(i))
			D_ERROR
		i = i + 1;
	}
	return (1);
}
#endif

#ifdef	D_ISASCII
int				uf_test_isascii(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isascii(i) != ft_isascii(i))
			D_ERROR
		i = i + 1;
	}
	return (1);
}
#endif

#ifdef	D_ISALNUM
int				uf_test_isalnum(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isalnum(i) != ft_isalnum(i))
			D_ERROR
		i = i + 1;
	}
	return (1);
}
#endif

#ifdef	D_ISDIGIT
int				uf_test_isdigit(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isdigit(i) != ft_isdigit(i))
			D_ERROR
		i = i + 1;
	}
	return (1);
}
#endif

#ifdef	D_ISALPHA
int				uf_test_isalpha(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isalpha(i) != ft_isalpha(i))
			D_ERROR
		i = i + 1;
	}
	return (1);
}
#endif

#ifdef	D_ATOI
int				uf_test_atoi(void)
{
	size_t		i, j;
	char		str[12] = {0};

	if (atoi("\n\v\t\r\f -123") != ft_atoi("\n\v\t\r\f -123"))
		D_ERROR
	if (atoi("12-3") != ft_atoi("12-3"))
		D_ERROR
	if (atoi("-+123") != ft_atoi("-+123"))
		D_ERROR
	if (atoi("a123") != ft_atoi("a123"))
		D_ERROR
	if (atoi("123a") != ft_atoi("123a"))
		D_ERROR
	if (atoi("123") != ft_atoi("123"))
		D_ERROR
	if (atoi("-123") != ft_atoi("-123"))
		D_ERROR
	if (atoi("+123") != ft_atoi("+123"))
		D_ERROR
	if (atoi(" - 123") != ft_atoi(" - 123"))
		D_ERROR
	if (atoi("\t -123") != ft_atoi("\t -123"))
		D_ERROR
	if (atoi("-2147483648") != ft_atoi("-2147483648"))
		D_ERROR
	if (atoi("2147483647") != ft_atoi("2147483647"))
		D_ERROR
	if (atoi("") != ft_atoi(""))
		D_ERROR
	i = 0;
	while (i < RANDT)
	{
		j = 0;
		while (j < 11)
		{
			str[j] = ((char)rand() % 10) + '0';
			j++;
		}
		str[11] = 0;
		if (atoi(str) != ft_atoi(str))
			D_ERROR
		i++;
	}
	return (1);
}
#endif

/*
** Don't be stupid ppl, be careful with this noob noob noob test
*/

#ifdef	D_STRNCMP
int				uf_test_strncmp(void)
{
	int			a;

	a = ft_strncmp("abc", "abc", 2);
#ifdef  __clang__
	if (strncmp("abc", "abc", 2) != a)
		D_ERROR;
#else
	if (a)
		D_ERROR;
#endif

	a =  ft_strncmp("cba", "abc", 2);
#ifdef  __clang__
	if (strncmp("cba", "abc", 2) != a)
		D_ERROR;
#else
	if (!a)
		D_ERROR;
#endif

	a =  ft_strncmp("abc", "cba", 2);
#ifdef  __clang__
	if (strncmp("abc", "cba", 2) != a)
		D_ERROR;
#else
	if (!a)
		D_ERROR;
#endif

	a = ft_strncmp("", "", 3);
#ifdef  __clang__
	if (strncmp("", "", 3) != a)
		D_ERROR;
#else
	if (a)
		D_ERROR;
#endif

	a = ft_strncmp("q", "a", 0);
#ifdef  __clang__
	if (strncmp("q", "a", 0) != a)
		D_ERROR;
#else
	if (a)
		D_ERROR;
#endif

	a = ft_strncmp("abc", "abd", 2);
#ifdef  __clang__
	if(strncmp("abc", "abd", 2) != a)
		D_ERROR;
#else
	if (a)
		D_ERROR;
#endif

	return (1);
}
#endif

/*
** Don't be stupid ppl, be careful with this noob noob noob test
*/

#ifdef	D_STRCMP
int				uf_test_strcmp(void)
{
	int			a;

	a = ft_strcmp("abc", "abc");
#ifdef  __clang__
	if (a != strcmp("abc", "abc"))
		D_ERROR;
#endif
#ifndef  __clang__
	if (a)
		D_ERROR;
#endif
	a = ft_strcmp("cba", "abc");
#ifdef  __clang__
	if (a != strcmp("cba", "abc"))
		D_ERROR;
#endif
#ifndef  __clang__
	if (!a)
		D_ERROR;
#endif
	a = ft_strcmp("abc", "cba");
#ifdef  __clang__
	if (a != strcmp("abc", "cba"))
		D_ERROR;
#endif
#ifndef  __clang__
	if (!a)
		D_ERROR;
#endif
	if (ft_strcmp("", "") != strcmp("", ""))
		D_ERROR;
	return (1);
}
#endif

#ifdef	D_STRNSTR
int				uf_test_strnstr(void)
{
	char		*str = "Hello les genw";


	if (strnstr(str, "Hello", 6) != ft_strnstr(str, "Hello", 6))
		D_ERROR;
	if (strnstr(str, "Hello", 3) != ft_strnstr(str, "Hello", 3))
		D_ERROR;
	if (strnstr(str, "les", 1) != ft_strnstr(str, "les", 1))
		D_ERROR;
	if (strnstr(str, "gen", 2) != ft_strnstr(str, "gen", 2))
		D_ERROR;
	if (strnstr(str, "w", 0) != ft_strnstr(str, "w", 0))
		D_ERROR;
	if (strnstr(str, "", 3) != ft_strnstr(str, "", 3))
		D_ERROR;
	return (1);
}
#endif

#ifdef	D_STRSTR
int				uf_test_strstr(void)
{
	char		*str = "Hello les genw";

	if (strstr(str, "Hello") != ft_strstr(str, "Hello"))
		D_ERROR;
	if (strstr(str, "les") != ft_strstr(str, "les"))
		D_ERROR;
	if (strstr(str, "gen") != ft_strstr(str, "gen"))
		D_ERROR;
	if (strstr(str, "w") != ft_strstr(str, "w"))
		D_ERROR;
	if (strstr(str, "") != ft_strstr(str, ""))
		D_ERROR;
	if (strstr("", "") != ft_strstr("", ""))
		D_ERROR;
	return (1);
}
#endif

#ifdef	D_STRRCHR
int				uf_test_strrchr(void)
{
	char		str[] = "Hello je tesx";

	if (strrchr(str, 'H') != ft_strrchr(str, 'H'))
	{
		printf("notre=%s\nvotre=%s\n", strrchr(str, 'H'), ft_strrchr(str, 'H'));
		D_ERROR
	}
	if (strrchr(str, 'j') != ft_strrchr(str, 'j'))
	{
		printf("\nnotre=%s\nvotre=%s\n", strrchr(str, 'j'), ft_strrchr(str, 'j'));
        D_ERROR
	}
	if (strrchr(str, 'x') != ft_strrchr(str, 'x'))
	{
		printf("\nnotre=%s\nvotre=%s\n", strrchr(str, 'x'), ft_strrchr(str, 'x'));
        D_ERROR
	}
	if (strrchr(str, 0) != ft_strrchr(str, 0))
	{
		printf("\nnotre=%s\nvotre=%s\n", strrchr(str, 0), ft_strrchr(str, 0));
        D_ERROR
	}
	return (1);
}
#endif

#ifdef	D_STRCHR
int				uf_test_strchr(void)
{
	char		str[] = "Hello je tesx";

	if (strchr(str, 'H') != ft_strchr(str, 'H'))
		D_ERROR
	if (strchr(str, 'j') != ft_strchr(str, 'j'))
		D_ERROR
	if (strchr(str, 'x') != ft_strchr(str, 'x'))
		D_ERROR
	if (strchr(str, 'y') != ft_strchr(str, 'y'))
		D_ERROR
	if (strchr(str, 0) != ft_strchr(str, 0))
		D_ERROR
	return (1);
}
#endif

/*
** Not HardCore but better than original
** Fixes by pmotte
*/

#ifdef	D_STRLCAT
int				uf_test_strlcat(void)
{
	char		dest[50] = {0};
	char		dest2[50] = {0};
	size_t		i, j, k;

	if (strlcat(dest, "Hello ", 4) != ft_strlcat(dest2, "Hello ", 4))
		D_ERROR
	memset(dest, 0, sizeof(dest));
	memset(dest2, 0, sizeof(dest));
	j = strlcat(dest, "Hello ", 4);
	k = ft_strlcat(dest2, "Hello ", 4);
	if (strcmp(dest, dest2) != 0 || j != k)
		D_ERROR
	j = strlcat(dest, "Hello ", 1);
	k = ft_strlcat(dest2, "Hello ", 1);
	if (strcmp(dest, dest2) != 0 || j != k)
		D_ERROR
	i = 0;
	while (i < 6)
	{
		dest[4 + i] = 'z';
		dest2[4 + i] = 'z';
		++i;
	}
	j = strlcat(dest, "abc", 6);
	k = ft_strlcat(dest2, "abc", 6);
	if (strcmp(dest, dest2) != 0 || j != k)
		D_ERROR
	return (1);
}
#endif

/*
** Better than original by mfontain
*/

#ifdef	D_STRNCAT
int				uf_test_strncat(void)
{
	char		dest[50] = {0};
	char		dest2[50] = {0};

	if (strncat(dest, "hello ", 2) != ft_strncat(dest, "hello ", 2))
		D_ERROR
	memset(dest, 0, sizeof(dest));
	strncat(dest, "Hello ", 4);
	ft_strncat(dest2, "Hello ", 4);
	if (strcmp(dest, dest2) != 0)
		D_ERROR
	strncat(dest, "Hello ", 2);
	ft_strncat(dest2, "Hello ", 2);
	if (strcmp(dest, dest2) != 0)
		D_ERROR
	strncat(dest, "Hello ", 10);
    	ft_strncat(dest2, "Hello ", 10);
    	if (strcmp(dest, dest2) != 0)
    	    D_ERROR
	strncat(dest, "1234\n78", 7);
    	ft_strncat(dest2, "1234\n78", 7);
    	if (strcmp(dest, dest2) != 0)
        	D_ERROR
	return (1);
}
#endif

#ifdef	D_STRCAT
int				uf_test_strcat(void)
{
	char		dest[50] = {0};
	char		dest2[50] = {0};

	if (strcat(dest, "hello ") != ft_strcat(dest, "hello "))
		D_ERROR
	memset(dest, 0, sizeof(dest));
	strcat(dest, "Hello ");
	ft_strcat(dest2, "Hello ");
	if (strcmp(dest, dest2) != 0)
		D_ERROR
	strcat(dest, "Hello ");
	ft_strcat(dest2, "Hello ");
	if (strcmp(dest, dest2) != 0)
		D_ERROR
	return (1);
}
#endif

#ifdef	D_STRNCPY
int				uf_test_strncpy(void)
{
	char		ctab[11], ctab2[21], ctab3[21];
	int			i, j;
	size_t		k;

	k = 0;
	while (k < 21)
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 21)
			{
				if (j < 11)
					ctab[j] = ((char)rand() % 26) + 'a';
				ctab2[j] = 'Z';
				ctab3[j] = 'Z';
				j++;
			}
			ctab[10] = 0;
			ctab2[20] = 0;
			ctab3[20] = 0;
			if (strncpy(ctab2, ctab, k) != ctab2 || ft_strncpy(ctab3, ctab, k) != ctab3)
				D_ERROR
			if (strcmp(ctab2, ctab3))
				D_ERROR
			++i;
		}
		k++;
	}
	return (1);
}
#endif

#ifdef	D_STRCPY
int				uf_test_strcpy(void)
{
	char		dest[50] = {0};
	char		dest2[50] = {0};


	char			ctab[11], ctab2[11], ctab3[11];
    int				i, j;
    size_t			k;

    k = 0;
    while (k <= sizeof(ctab))
    {
        i = 0;
        while (i < RANDT)
        {
            j = 0;
            while (j < 11)
            {
                ctab[j] = (char)rand();
                ctab2[j] = 0; ctab3[j] = 0;
                j++;
            }
			ctab[10] = 0;
			if (strcpy(ctab2, ctab) != ctab2 || ft_strcpy(ctab3, ctab) != ctab3)
				D_ERROR
			if (strcmp(ctab2, ctab3))
                D_ERROR
			++i;
		}
		k++;
	}
	if (strcpy(dest, "Hello foo") != ft_strcpy(dest, "Hello foo"))
		D_ERROR
	strcpy(dest, "Hello foo");
	ft_strcpy(dest2, "Hello foo");
	if (strcmp(dest, dest2) != 0)
		D_ERROR
	strcpy(dest, "Hello");
	ft_strcpy(dest2, "Hello");
	if (strcmp(dest, dest2) != 0)
		D_ERROR
	return (1);
}
#endif

#ifdef	D_STRDUP
int				uf_test_strdup(void)
{
	char		*ret1;
	char		*ret2;

	ret1 = strdup("");
	ret2 = ft_strdup("");
	if (strcmp(ret1, ret2) != 0)
		D_ERROR
	free(ret1);
	free(ret2);
	ret1 = strdup("hello");
	ret2 = ft_strdup("hello");
	if (strcmp(ret1, ret2) != 0)
		D_ERROR
	free(ret1);
	free(ret2);
	return (1);
}
#endif

#ifdef	D_STRLEN
int				uf_test_strlen(void)
{
	if (strlen("") != ft_strlen(""))
		D_ERROR
	if (strlen("abc") != ft_strlen("abc"))
		D_ERROR
	if (strlen("a") != ft_strlen("a"))
		D_ERROR
	return (1);
}
#endif

#ifdef	D_MEMMOVE
int				uf_test_memmove(void)
{
	char		str[] = "memmove can be very useful......";
	char		str2[] = "memmove can be very useful......";
	char		str3[] = "memmove can be very useful......";
	char		str4[] = "memmove can be very useful......";

	char		s1[101], t1[101];
	char		s2[101], t2[101];
	size_t		i, j;

	i = 0;
	while (i < RANDT)
	{
		j = 0;
		while (j < 100)
		{
			s1[j] = (char)rand();
			s2[j] = (char)rand();
			j++;
		}
		s1[100] = 0;    s2[100] = 0;
		memcpy(t1, s1, sizeof(s1));
		memcpy(t2, s2, sizeof(s2));
		if (strcmp(memmove(str + 10, str + 5, 10), ft_memmove(str2 + 10, str2 + 5, 10)) != 0)
			D_ERROR
		if (strcmp(memmove(str3 + 5, str3 + 10, 10), ft_memmove(str4 + 5, str4 + 10, 10)) != 0)
			D_ERROR
		if (strcmp(memmove(s1, s2, 2), ft_memmove(t1, t2, 2)) != 0)
			D_ERROR
		if (strcmp(memmove(s1, s1 + 25, 30), ft_memmove(t1, t1 + 25, 30)) != 0)
			D_ERROR
		if (strcmp(memmove(s1 + 30, s1, 40), ft_memmove(t1 + 30, t1, 40)) != 0)
			D_ERROR
		++i;
	}
	return (1);
}
#endif

#ifdef	D_MEMCHR
int				uf_test_memchr(void)
{
	char			ctab[11];
	int				itab[11];
	unsigned long	ltab[11];
	size_t			j;
	int				i;

	i = -300;
	memchr(NULL, 0, 0);
	ft_memchr(NULL, 0, 0);
	while (i < 300)
	{
		j = 0;
		while (j < 11)
		{
			ctab[j] = (char)rand();
			itab[j] = rand();
			ltab[j] = (unsigned long)rand() * LONG;
			j++;
		}
		if (memchr(ctab, i, sizeof(ctab)) != ft_memchr(ctab, i, sizeof(ctab)))
			D_ERROR
		if (memchr(itab, i, sizeof(itab)) != ft_memchr(itab, i, sizeof(itab)))
			D_ERROR
		if (memchr(ltab, i, sizeof(ltab)) != ft_memchr(ltab, i, sizeof(ltab)))
			D_ERROR
		++i;
	}
	return (1);
}
#endif

#ifdef	D_MEMCMP
int				uf_test_memcmp(void)
{
    char            ctab[11], ctab2[11];
    int             itab[11], itab2[11];
    unsigned long   ltab[11], ltab2[11];
    size_t          i, j;

#ifdef	__clang__
	if (memcmp(NULL, NULL, 0) != ft_memcmp(NULL, NULL, 0))
		D_ERROR
#endif
    i = 0;
    while (i < 11)
    {
        j = 0;
        while (j < 11)
        {
            ctab[j] = (char)rand();
            ctab2[j] = (char)rand();
			itab[j] = rand();
			itab2[j] = rand();
            ltab[j] = (unsigned long)rand() * LONG;
			ltab2[j] = (unsigned long)rand() * LONG;
            j++;
        }
		if (memcmp(ctab, ctab2, sizeof(ctab)) != ft_memcmp(ctab, ctab2, sizeof(ctab)))
            D_ERROR
        memcpy(ctab2, ctab, sizeof(ctab));
		if (memcmp(ctab, ctab2, sizeof(ctab)) != ft_memcmp(ctab, ctab2, sizeof(ctab)))
            D_ERROR
		if (memcmp(itab, itab2, sizeof(itab)) != ft_memcmp(itab, itab2, sizeof(itab)))
            D_ERROR
		memcpy(itab2, itab, sizeof(itab));
        if (memcmp(itab, itab2, sizeof(itab)) != ft_memcmp(itab, itab2, sizeof(itab)))
            D_ERROR
		if (memcmp(ltab, ltab2, sizeof(ltab)) != ft_memcmp(ltab, ltab2, sizeof(ltab)))
            D_ERROR
		memcpy(ltab2, ltab, sizeof(ltab));
        if (memcmp(ltab, ltab2, sizeof(ltab)) != ft_memcmp(ltab, ltab2, sizeof(ltab)))
            D_ERROR
				++i;
    }
	return (1);
}
#endif

#ifdef	D_MEMCCPY
int				uf_test_memccpy(void)
{
	char			ctab[11], ctab2[11], ctab3[11];
	int				itab[11], itab2[11], itab3[11];
	unsigned long	ltab[11], ltab2[11], ltab3[11];
	int				i, j;
	size_t			k;
	void			*temp, *temp2;

#ifdef	__clang__
	memccpy(NULL, NULL, 0, 0);
	ft_memccpy(NULL, NULL, 0, 0);
#endif
	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				itab[j] = rand();
				itab2[j] = 0; itab3[j] = 0;
				ltab[j] = (unsigned long)rand() * LONG;
				ltab2[j] = 0; ltab3[j] = 0;
				j++;
			}
			temp = memccpy(ctab2, ctab, 'a', (k < sizeof(ctab)) ? k : sizeof(ctab));
			memcpy(ctab3, ctab2, sizeof(ctab));
			temp2 = ft_memccpy(ctab2, ctab, 'a', (k < sizeof(ctab)) ? k : sizeof(ctab));
			if ((memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || (temp != temp2)))
				D_ERROR
			temp = memccpy(itab2, itab, 'a', (k < sizeof(itab)) ? k : sizeof(itab));
			memcpy(itab3, itab2, sizeof(itab));
			temp2 = ft_memccpy(itab2, itab, 'a', (k < sizeof(itab)) ? k : sizeof(itab));
			if ((memcmp(itab2, itab3, sizeof(itab)) != 0 || (temp != temp2)))
				D_ERROR
			temp = memccpy(ltab2, ltab, 'a', (k < sizeof(ltab)) ? k : sizeof(ltab));
			memcpy(ltab3, ltab2, sizeof(ltab));
			temp2 = ft_memccpy(ltab2, ltab, 'a', (k < sizeof(ltab)) ? k : sizeof(ltab));
			if ((memcmp(ltab2, ltab3, sizeof(ltab)) != 0 || (temp != temp2)))
				D_ERROR
			++i;
		}
		++k;
	}
	return (1);
}
#endif

#ifdef	D_MEMCPY
int					uf_test_memcpy(void)
{
	char			ctab[11], ctab2[11], ctab3[11];
	int				itab[11], itab2[11], itab3[11];
	unsigned long	ltab[11], ltab2[11], ltab3[11];
	int				i, j;
	size_t			k;
	void			*temp, *temp2, *temp3;

#ifdef	__clang__
	memcpy(NULL, NULL, 0);
	ft_memcpy(NULL, NULL, 0);
#endif
	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				itab[j] = rand();
				itab2[j] = 0; itab3[j] = 0;
				ltab[j] = (unsigned long)rand() * LONG;
				ltab2[j] = 0; ltab3[j] = 0;
				j++;
			}
			memcpy(ctab2, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp = ft_memcpy(ctab3, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			memcpy(itab2, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = ft_memcpy(itab3, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			memcpy(ltab2, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp3 = ft_memcpy(ltab3, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			if ((memcmp(itab2, itab3, sizeof(itab)) != 0 || (temp2 != itab3)))
				D_ERROR
			if (memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || temp != ctab3)
				D_ERROR
			if (memcmp(ltab2, ltab3, sizeof(ltab)) != 0 ||( temp3 != ltab3))
				D_ERROR
			++i;
		}
		++k;
	}
	return (1);
}
#endif

#ifdef	D_MEMSET
int					uf_test_memset(void)
{
	char			ctab[11], ctab2[11];
	int				itab[11], itab2[11];
	unsigned long	ltab[11], ltab2[11];
	size_t			i, j, k;
	void			*temp, *temp2;

#ifdef	__clang__
	memset(NULL, 0, 0);
	ft_memset(NULL, 0, 0);
#endif
	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				itab[j] = rand();
				ltab[j] = (unsigned long)rand() * LONG;
				j++;
			}
			memcpy(ctab2, ctab, sizeof(ctab));
			memcpy(itab2, itab, sizeof(itab));
			memcpy(ltab2, ltab, sizeof(ltab));
			temp = ft_memset(itab, i, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = memset(itab2, i, (k < sizeof(itab)) ? k : sizeof(itab));
			if (memcmp(itab, itab2, sizeof(itab)) != 0 || temp != itab || temp2 != itab2)
				D_ERROR
			temp = ft_memset(ctab, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp2 = memset(ctab2, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			if (memcmp(ctab, ctab2, sizeof(ctab)) != 0 || temp != ctab || temp2 != ctab2)
				D_ERROR
			temp = ft_memset(ltab, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp2 = memset(ltab2, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			if (memcmp(ltab, ltab2, sizeof(ltab)) != 0 || temp != ltab || temp2 != ltab2)
				D_ERROR
			++i;
		}
		++k;
	}
	return (1);
}
#endif

#ifdef	D_BZERO
int					uf_test_bzero(void)
{
	char			ctab[11], ctab2[11];
	int				itab[11], itab2[11];
	unsigned long	ltab[11], ltab2[11];
	size_t			i, j;

	i = 0;
#ifdef	__clang__
	bzero(NULL, 0);
	ft_bzero(NULL, 0);
#endif
	while (i < 11)
	{
		j = 0;
		while (j < 11)
		{
			ctab[j] = (char)rand();
			itab[j] = rand();
			ltab[j] = (unsigned long)rand() * LONG;
			j++;
		}
		memcpy(ctab2, ctab, sizeof(ctab));
		memcpy(itab2, itab, sizeof(itab));
		memcpy(ltab2, ltab, sizeof(ltab));
		bzero(ctab2, i);
		ft_bzero(ctab, i);
		if (memcmp(ctab, ctab2, sizeof(ctab)) != 0)
			D_ERROR
		bzero(itab2, i);
		ft_bzero(itab, i);
		if (memcmp(itab, itab2, sizeof(itab)) != 0)
			D_ERROR
		bzero(ltab2, i);
		ft_bzero(ltab, i);
		if (memcmp(ltab, ltab2, sizeof(ltab)) != 0)
			D_ERROR
		++i;
	}
	return (1);
}
#endif

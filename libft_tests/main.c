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

UT_TEST(ft_memalloc)
{
	void	*mem1, *mem2;

	mem1 = malloc(100);
	bzero(mem1, 100);
	mem2 = ft_memalloc(100);
	UT_ASSERT_EQ(memcmp(mem1, mem2, 100), 0);
	UT_ASSERT_EQ(ft_memalloc(0), NULL);
	UT_ASSERT_EQ(ft_memalloc((size_t)-1), NULL);
}

UT_TEST(ft_memdel)
{
	void	*mem;

	mem = malloc(2000);
	ft_memdel(&mem);
	UT_ASSERT_EQ(mem, NULL);
}

UT_TEST(ft_strnew)
{
	char	*str;
	char	*t;

	str = ft_strnew(0);
	UT_ASSERT_NEQ(str, NULL);
	str = ft_strnew(100);
	t = malloc(101);
	bzero(t, 101);
	UT_ASSERT_EQ(memcmp(str, t, 101), 0);
	UT_ASSERT_NEQ(ft_strnew(0), 0);
	UT_ASSERT_EQ(ft_strnew((size_t)-10), 0);
}

UT_TEST(ft_strdel)
{
	char	*str;

	str = malloc(123);
	ft_strdel(&str);
	UT_ASSERT_EQ(str, NULL);
}

UT_TEST(ft_strclr)
{
	char	str[] = "tttttt";

	ft_strclr(str);
	UT_ASSERT_EQ(memcmp(str, "\0\0\0\0\0\0", 7), 0);
}

void	it_test(char *c)
{
	*c = *c + 1;
}

UT_TEST(ft_striter)
{
	char	str[] = "aBcDeF";

	ft_striter(str, it_test);
	UT_ASSERT_EQ(strcmp(str, "bCdEfG"), 0);
}

void	iti_test(unsigned int i, char *c)
{
	*c = *c + i;
}

UT_TEST(ft_striteri)
{
	char	str[] = "aBcDeF";

	ft_striteri(str, iti_test);
	UT_ASSERT_EQ(strcmp(str, "aCeGiK"), 0);
}

char	map_test(char c)
{
	return (c + 1);
}

UT_TEST(ft_strmap)
{
	char	*str;

	str = "abcde";
	str = ft_strmap(str, map_test);
	UT_ASSERT_EQ(strcmp(str, "bcdef"), 0);
}

char	mapi_test(unsigned int i, char c)
{
	return (c + i);
}

UT_TEST(ft_strmapi)
{
	char	*str;

	str = "abcde";
	str = ft_strmapi(str, mapi_test);
	UT_ASSERT_EQ(strcmp(str, "acegi"), 0);
}

UT_TEST(ft_strequ)
{
	UT_ASSERT_EQ(ft_strequ("", ""), 1);
	UT_ASSERT_EQ(ft_strequ("abcDEF", "abcDEF"), 1);
	UT_ASSERT_EQ(ft_strequ("abcDEF", "abcDEf"), 0);
}

UT_TEST(ft_strnequ)
{
	UT_ASSERT_EQ(ft_strnequ("ededeqdf", "", 0), 1);
	UT_ASSERT_EQ(ft_strnequ("abcde", "abdfe", 2), 1);
	UT_ASSERT_EQ(ft_strnequ("abc", "abc", 100), 1);
	UT_ASSERT_EQ(ft_strnequ("abcde", "abdde", 5), 0);
}

UT_TEST(ft_strsub)
{
	char	*str;

	str = "Un jour je serai, le meilleur dresseur !";
	UT_ASSERT_EQ(ft_strsub(str, 0, (size_t)-10), NULL);
	UT_ASSERT_EQ(strcmp(ft_strsub(str, 8, 8), "je serai"), 0);
	UT_ASSERT_EQ(strcmp(ft_strsub(str, 0, 0), ""), 0);
}

UT_TEST(ft_strjoin)
{
	UT_ASSERT_EQ(strcmp(ft_strjoin("abc", "def"), "abcdef"), 0);
	UT_ASSERT_EQ(strcmp(ft_strjoin("", ""), ""), 0);
}

UT_TEST(ft_strtrim)
{
	UT_ASSERT_EQ(strcmp(ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t"), "AAA \t BBB"), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrim("\t\t\n\t\t   "), ""), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrim(""), ""), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrim("abc"), "abc"), 0);
}

UT_TEST(ft_strsplit)
{
	char	**tt;

	tt = ft_strsplit("***salut****!**", '*');
	UT_ASSERT_EQ(strcmp(tt[0], "salut"), 0);
	UT_ASSERT_EQ(strcmp(tt[1], "!"), 0);
	UT_ASSERT_EQ(tt[2], NULL);
	tt = ft_strsplit("*****", '*');
	UT_ASSERT_EQ(tt[0], NULL);
	tt = ft_strsplit("coucou", '*');
	UT_ASSERT_EQ(strcmp(tt[0], "coucou"), 0);
	UT_ASSERT_EQ(tt[1], NULL);
}

UT_TEST(ft_itoa)
{
	UT_ASSERT_EQ(strcmp(ft_itoa(0), "0"), 0);
	UT_ASSERT_EQ(strcmp(ft_itoa(-1234), "-1234"), 0);
	UT_ASSERT_EQ(strcmp(ft_itoa(123456000), "123456000"), 0);
	UT_ASSERT_EQ(strcmp(ft_itoa(-2147483648), "-2147483648"), 0);
}

UT_TEST(ft_putchar)
{
	int		out;
	int		p[2];
	char	buf[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putchar('a');
	ft_putchar('b');
	ft_putchar('c');
	dup2(out, 1);
	read(p[0], buf, 3);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	UT_ASSERT_EQ(strcmp(buf, "abc"), 0);
}

UT_TEST(ft_putstr)
{
	int		out;
	int		p[2];
	char	buf[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putstr("aaa");
	dup2(out, 1);
	read(p[0], buf, 3);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	UT_ASSERT_EQ(strcmp(buf, "aaa"), 0);
}

UT_TEST(ft_putendl)
{
	int		out;
	int		p[2];
	char	buf[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putendl("aa");
	dup2(out, 1);
	read(p[0], buf, 3);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	UT_ASSERT_EQ(strcmp(buf, "aa\n"), 0);
}

UT_TEST(ft_putnbr)
{
	int		out;
	int		p[2];
	char	buf[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putnbr(0);
	ft_putnbr(1);
	ft_putnbr(-1);
	ft_putnbr(12300);
	ft_putnbr(10203);
	ft_putnbr(-56);
	ft_putnbr(2147483647);
	ft_putnbr(-2147483648);
	dup2(out, 1);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	UT_ASSERT_EQ(strcmp(buf, "01-11230010203-562147483647-2147483648"), 0);
}

UT_TEST(ft_putchar_fd)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putchar_fd('a', p[1]);
	ft_putchar_fd('b', p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	UT_ASSERT_EQ(strcmp(buf, "ab"), 0);
}

UT_TEST(ft_putstr_fd)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putstr_fd("A QUE KOUKOU", p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	UT_ASSERT_EQ(strcmp(buf, "A QUE KOUKOU"), 0);
}

UT_TEST(ft_putendl_fd)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putendl_fd("A QUE KOUKOU", p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	UT_ASSERT_EQ(strcmp(buf, "A QUE KOUKOU\n"), 0);
}

UT_TEST(ft_putnbr_fd)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putnbr_fd(0, p[1]);
	ft_putnbr_fd(1, p[1]);
	ft_putnbr_fd(-1, p[1]);
	ft_putnbr_fd(56, p[1]);
	ft_putnbr_fd(-1230, p[1]);
	ft_putnbr_fd(10203, p[1]);
	ft_putnbr_fd(2147483647, p[1]);
	ft_putnbr_fd(-2147483648, p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	UT_ASSERT_EQ(strcmp(buf, "01-156-1230102032147483647-2147483648"), 0);
}

#endif

#ifdef BONUS

UT_TEST(ft_lstnew)
{
	t_list	*list;
	int		ft;

	ft = 42;
	list = ft_lstnew(&ft, sizeof(int));
	UT_ASSERT_EQ((*(int*)(list->content)), 42);
	list = ft_lstnew(NULL, 386);
	UT_ASSERT_EQ((list->content_size), 0);
}

int		____diddel;

void	del_test(void *data, size_t i)
{
	(void)data;
	(void)i;
	____diddel++;
}

UT_TEST(ft_lstdelone)
{
	t_list	*list;
	int		ft;

	____diddel = 0;
	ft = 42;
	list = (t_list *)malloc(sizeof(t_list));
	list->content = &ft;
	list->content_size = sizeof(int);
	ft_lstdelone(&list, del_test);
	UT_ASSERT_EQ(list, NULL);
	UT_ASSERT_EQ(____diddel, 1);
	ft_lstdelone(NULL, NULL);
}

UT_TEST(ft_lstdel)
{
	t_list	*list;
	int		ft;

	ft = 42;
	____diddel = 0;
	list = malloc(sizeof(t_list));
	bzero(list, sizeof(t_list));
	list->next = malloc(sizeof(t_list));
	bzero(list->next, sizeof(t_list));
	list->content = &ft;
	list->next->content = (&ft) + 1;
	ft_lstdel(&list, del_test);
	UT_ASSERT_EQ(list, NULL);
	UT_ASSERT_EQ(____diddel, 2);
	ft_lstdel(NULL, NULL);
}

UT_TEST(ft_lstadd)
{
	t_list	*list;
	t_list	*list2;

	list = malloc(sizeof(t_list));
	list2 = malloc(sizeof(t_list));
	bzero(list, sizeof(t_list));
	bzero(list2, sizeof(t_list));
	ft_lstadd(&list2, list);
	UT_ASSERT_EQ(list, list2);
	UT_ASSERT_NEQ(list->next, NULL);
	ft_lstadd(NULL, NULL);
}

void	lstiter_test(t_list *ppp)
{
	ppp->content_size = 42;
}

UT_TEST(ft_lstiter)
{
	t_list	*list;

	bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
	bzero(((list->next) = malloc(sizeof(t_list))), sizeof(t_list));
	ft_lstiter(list, lstiter_test);
	UT_ASSERT_EQ(list->content_size, 42);
	UT_ASSERT_EQ(list->next->content_size, 42);
}

t_list	*lstmap_test(t_list *list)
{
	t_list	*l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content_size = list->content_size * 2;
	return (l2);
}

UT_TEST(ft_lstmap)
{
	t_list	*list;
	t_list	*map;

	bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
	bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
	list->content_size = 21;
	list->next->content_size = 100;
	map = ft_lstmap(list, lstmap_test);
	UT_ASSERT_EQ(list->content_size, 21);
	UT_ASSERT_EQ(list->next->content_size, 100);
	UT_ASSERT_EQ(map->content_size, 42);
	UT_ASSERT_EQ(map->next->content_size, 200);
}

#endif

#ifdef TEST_ft_putnendl
UT_TEST(ft_putnendl)
{
	int		out;
	int		p[2];
	char	buf[5];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putnendl("Bonjour", 4);
	dup2(out, 1);
	read(p[0], buf, 5);
	buf[5] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	UT_ASSERT_EQ(strcmp(buf, "Bonj\n"), 0);
}
#endif

#ifdef TEST_ft_putnstr
UT_TEST(ft_putnstr)
{
	int		out;
	int		p[2];
	char	buf[5];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putnstr("Bonjour", 4);
	dup2(out, 1);
	read(p[0], buf, 4);
	buf[4] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	UT_ASSERT_EQ(strcmp(buf, "Bonj"), 0);
}
#endif

#ifdef TEST_ft_sqrt
UT_TEST(ft_sqrt)
{
	UT_ASSERT_EQ(ft_sqrt(25), 5);
	UT_ASSERT_EQ(ft_sqrt(100), 10);
	UT_ASSERT_EQ(ft_sqrt(18), 0);
	UT_ASSERT_EQ(ft_sqrt(0), 0);
}
#endif

#ifdef TEST_ft_power
UT_TEST(ft_power)
{
	UT_ASSERT_EQ(ft_power(2, 3), pow(2, 3));
	UT_ASSERT_EQ(ft_power(10, 9), pow(10, 9));
	UT_ASSERT_EQ(ft_power(50, 0), pow(50, 0));
	UT_ASSERT_EQ(ft_power(0, 10), pow(0, 10));
	UT_ASSERT_EQ(ft_power(25, 13), pow(25,13));
}
#endif

#ifdef TEST_ft_sort_int_table
UT_TEST(ft_sort_int_table)
{
	int test_ft_sort[7] = {42,4,98,9,12,68,21};

	ft_sort_int_table(test_ft_sort, 7);
	UT_ASSERT_EQ(test_ft_sort[0], 4);
	UT_ASSERT_EQ(test_ft_sort[1], 9);
	UT_ASSERT_EQ(test_ft_sort[2], 12);
	UT_ASSERT_EQ(test_ft_sort[3], 21);
	UT_ASSERT_EQ(test_ft_sort[4], 42);
	UT_ASSERT_EQ(test_ft_sort[5], 68);
	UT_ASSERT_EQ(test_ft_sort[6], 98);
}
#endif

#ifdef TEST_ft_memswap
UT_TEST(ft_memswap)
{     /* Two contributor for this test */
	char	was_a = 'a';
	char	was_b = 'b';
	int		was_1 = 1;
	int		was_2 = 2;
	char	was_toto[] = "toto";
	char	was_tata[] = "tata";

	char test_swap_str_1[] = "coucou les filles";
	char test_swap_str_2[] = "bonjour jambon po";
	int test_swap_int_1 = 24;
	int test_swap_int_2 = 42;

	ft_memswap(&was_a, &was_b, sizeof(char));
	UT_ASSERT(was_a == 'b');
	UT_ASSERT(was_b == 'a');
	ft_memswap(&was_1, &was_2, sizeof(int));
	UT_ASSERT(was_1 == 2);
	UT_ASSERT(was_2 == 1);
	ft_memswap(&was_1, &was_2, 0);
	UT_ASSERT(was_1 == 2);
	UT_ASSERT(was_2 == 1);
	ft_memswap(was_toto, was_tata, sizeof(char) * 2);
	UT_ASSERT_EQ(strcmp(was_toto, "tato"), 0);
	UT_ASSERT_EQ(strcmp(was_tata, "tota"), 0);

	ft_memswap(&test_swap_str_1, &test_swap_str_2, ft_strlen(test_swap_str_2));
	ft_memswap(&test_swap_int_1, &test_swap_int_2, 2);
	UT_ASSERT_EQ(strcmp(test_swap_str_1, "bonjour jambon po"), 0);
	UT_ASSERT_EQ(strcmp(test_swap_str_2, "coucou les filles"), 0);
	UT_ASSERT_EQ(test_swap_int_1, 42);
	UT_ASSERT_EQ(test_swap_int_2, 24);
}
#endif

#ifdef TEST_ft_factorial
UT_TEST(ft_factorial)
{
	UT_ASSERT_EQ(ft_factorial(0), 1);
	UT_ASSERT_EQ(ft_factorial(1), 1);
	UT_ASSERT_EQ(ft_factorial(3), 6);
	UT_ASSERT_EQ(ft_factorial(5), 120);
	UT_ASSERT_EQ(ft_factorial(8), 40320);
	UT_ASSERT_EQ(ft_factorial(20), 2432902008176640000);
}
#endif

#ifdef TEST_ft_strcapitalize
UT_TEST(ft_strcapitalize)
{
	ft_strcapitalize(NULL);
	UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("bonjour les filles")), "Bonjour Les Filles"), 0);
	UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("hello")), "Hello"), 0);
	UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("hello2world")), "Hello2world"), 0);
	UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("   je mange des pommes.  ")), "   Je Mange Des Pommes.  "), 0);
}
#endif

#ifdef TEST_ft_swap
UT_TEST(ft_swap)
{
	int test_swap1 = 24;
	int test_swap2 = 42;
	ft_swap(&test_swap1, &test_swap2);
	UT_ASSERT_EQ(test_swap1, 42);
	UT_ASSERT_EQ(test_swap2, 24);
}
#endif

#ifdef TEST_ft_strrev
UT_TEST(ft_strrev)
{
	char	buf1[] = "123456";
	char	buf2[] = "12345";
	char	buf3[] = "1";
	char	buf4[] = "";

	UT_ASSERT_EQ(strcmp(ft_strrev(buf1), "654321"), 0);
	UT_ASSERT_EQ(strcmp(ft_strrev(buf2), "54321"), 0);
	UT_ASSERT_EQ(strcmp(ft_strrev(buf3), "1"), 0);
	UT_ASSERT_EQ(strcmp(ft_strrev(buf4), ""), 0);
}
#endif

#ifdef TEST_ft_memdup
UT_TEST(ft_memdup)
{
	char	*c;

	c = "AbC";
	UT_ASSERT_EQ(strcmp(ft_memdup("aaaaa", 6), "aaaaa"), 0);
	UT_ASSERT_EQ(strcmp(ft_memdup("", 1), ""), 0);
	UT_ASSERT_NEQ(c, ft_memdup(c, 4));
}
#endif

#ifdef TEST_ft_isblank
UT_TEST(ft_isblank)
{
	UT_ASSERT_EQ(ft_isblank('\n'), isblank('\n'));
	UT_ASSERT_EQ(ft_isblank(' '), isblank(' '));
	UT_ASSERT_EQ(ft_isblank('\t'), isblank('\t'));
	UT_ASSERT_EQ(ft_isblank('\v'), isblank('\v'));
	UT_ASSERT_EQ(ft_isblank('8'), isblank('8'));
	UT_ASSERT_EQ(ft_isblank('p'), isblank('p'));
	UT_ASSERT_EQ(ft_isblank('/'), isblank('/'));
	UT_ASSERT_EQ(ft_isblank('&'), isblank('&'));
}
#endif

#ifdef TEST_ft_isspace
UT_TEST(ft_isspace)
{
	UT_ASSERT_EQ(ft_isspace('\n'), isspace('\n'));
	UT_ASSERT_EQ(ft_isspace('\t'), isspace('\t'));
	UT_ASSERT_EQ(ft_isspace(' '), isspace(' '));
	UT_ASSERT_EQ(ft_isspace('\v'), isspace('\v'));
	UT_ASSERT_EQ(ft_isspace('p'), isspace('p'));
	UT_ASSERT_EQ(ft_isspace('9'), isspace('9'));
}
#endif
#ifdef TEST_ft_strtrimc
UT_TEST(ft_strtrimc)
{
	UT_ASSERT_EQ(strcmp(ft_strtrimc("*****AAA*****BBB*****", '*'), "AAA*****BBB"), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrimc("**********", '*'), ""), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrimc("", '*'), ""), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrimc("abc", '*'), "abc"), 0);

}
#endif

#ifdef TEST_ft_replace_char
UT_TEST(ft_replace_char)
{
	char test_change[] = "Coucou les filles";
	char *return_test_change;

	return_test_change = (char *)malloc(strlen(test_change) + 1);

	return_test_change = ft_replace_char(test_change, 'o', 'r');
	UT_ASSERT_EQ(strcmp(return_test_change, "Crucru les filles"), 0);
}
#endif

#ifdef TEST_ft_islower
UT_TEST(ft_islower)
{
	UT_ASSERT_EQ(ft_islower('t'), islower('t'));
	UT_ASSERT_EQ(ft_islower(';'), islower(';'));
	UT_ASSERT_EQ(ft_islower(' '), islower(' '));
	UT_ASSERT_EQ(ft_islower('@'), islower('@'));
	UT_ASSERT_EQ(ft_islower('%'), islower('%'));
	UT_ASSERT_EQ(ft_islower('\n'), islower('\n'));
	UT_ASSERT_EQ(ft_islower(12), islower(12));
	UT_ASSERT_EQ(ft_islower('N'), islower('N'));
	UT_ASSERT_EQ(ft_islower('P'), islower('P'));
	UT_ASSERT_EQ(ft_islower('o'), islower('o'));
	UT_ASSERT_EQ(ft_islower('1'), islower('1'));
}
#endif

#ifdef TEST_ft_isupper
UT_TEST(ft_isupper)
{
	UT_ASSERT_EQ(ft_isupper('t'), isupper('t'));
	UT_ASSERT_EQ(ft_isupper(';'), isupper(';'));
	UT_ASSERT_EQ(ft_isupper(' '), isupper(' '));
	UT_ASSERT_EQ(ft_isupper('@'), isupper('@'));
	UT_ASSERT_EQ(ft_isupper('%'), isupper('%'));
	UT_ASSERT_EQ(ft_isupper('\n'), isupper('\n'));
	UT_ASSERT_EQ(ft_isupper(12), isupper(12));
	UT_ASSERT_EQ(ft_isupper('N'), isupper('N'));
	UT_ASSERT_EQ(ft_isupper('P'), isupper('P'));
	UT_ASSERT_EQ(ft_isupper('o'), isupper('o'));
	UT_ASSERT_EQ(ft_isupper('1'), isupper('1'));
}
#endif

#ifdef TEST_ft_ispunct
UT_TEST(ft_ispunct)
{
	UT_ASSERT_EQ(ft_ispunct('t'), ispunct('t'));
	UT_ASSERT_EQ(ft_ispunct(';'), ispunct(';'));
	UT_ASSERT_EQ(ft_ispunct(' '), ispunct(' '));
	UT_ASSERT_EQ(ft_ispunct('@'), ispunct('@'));
	UT_ASSERT_EQ(ft_ispunct('%'), ispunct('%'));
	UT_ASSERT_EQ(ft_ispunct('\n'), ispunct('\n'));
	UT_ASSERT_EQ(ft_ispunct(12), ispunct(12));
	UT_ASSERT_EQ(ft_ispunct('N'), ispunct('N'));
	UT_ASSERT_EQ(ft_ispunct('P'), ispunct('P'));
	UT_ASSERT_EQ(ft_ispunct('o'), ispunct('o'));
	UT_ASSERT_EQ(ft_ispunct('1'), ispunct('1'));
}
#endif

#ifdef TEST_ft_abs
UT_TEST(ft_abs)
{
	UT_ASSERT_EQ(ft_abs(12), abs(12));
	UT_ASSERT_EQ(ft_abs(-12), abs(-12));
	UT_ASSERT_EQ(ft_abs(28), abs(28));
	UT_ASSERT_EQ(ft_abs(0), abs(0));

}
#endif

#ifdef TEST_ft_rotone
UT_TEST(ft_rotone)
{
	UT_ASSERT_EQ(strcmp(ft_rotone(strdup("a")), "b"), 0);
	UT_ASSERT_EQ(strcmp(ft_rotone(strdup("A")), "B"), 0);
	UT_ASSERT_EQ(strcmp(ft_rotone(strdup("z")), "a"), 0);
	UT_ASSERT_EQ(strcmp(ft_rotone(strdup("Z")), "A"), 0);
	UT_ASSERT_EQ(strcmp(ft_rotone(strdup("6")), "6"), 0);
	UT_ASSERT_EQ(strcmp(ft_rotone(strdup("[")), "["), 0);
}
#endif

#ifdef TEST_ft_nrot
UT_TEST(ft_nrot)
{
	UT_ASSERT_EQ(strcmp(ft_nrot(strdup("a"), 1), "b"), 0);
	UT_ASSERT_EQ(strcmp(ft_nrot(strdup("A"), 5), "F"), 0);
	UT_ASSERT_EQ(strcmp(ft_nrot(strdup("A"), 22), "W"), 0);
}
#endif

#ifdef TEST_ft_printable_rotone
UT_TEST(ft_printable_rotone)
{

}
#endif

<TEST_DEF_BLOCK>

int	main(void)
{

#ifdef PART1
	UT_ADD_TEST(ft_memset);
	UT_ADD_TEST(ft_bzero);
	UT_ADD_TEST(ft_memcpy);
	UT_ADD_TEST(ft_memccpy);
	UT_ADD_TEST(ft_memmove);
	UT_ADD_TEST(ft_memchr);
	UT_ADD_TEST(ft_memcmp);
	UT_ADD_TEST(ft_strlen);
	UT_ADD_TEST(ft_strdup);
	UT_ADD_TEST(ft_strcpy);
	UT_ADD_TEST(ft_strncpy);
	UT_ADD_TEST(ft_strcat);
	UT_ADD_TEST(ft_strncat);
	UT_ADD_TEST(ft_strlcat);
	UT_ADD_TEST(ft_strchr);
	UT_ADD_TEST(ft_strrchr);
	UT_ADD_TEST(ft_strstr);
	UT_ADD_TEST(ft_strnstr);
	UT_ADD_TEST(ft_strcmp);
	UT_ADD_TEST(ft_strncmp);
	UT_ADD_TEST(ft_atoi);
	UT_ADD_TEST(ft_isalpha);
	UT_ADD_TEST(ft_isdigit);
	UT_ADD_TEST(ft_isalnum);
	UT_ADD_TEST(ft_isascii);
	UT_ADD_TEST(ft_isprint);
	UT_ADD_TEST(ft_toupper);
	UT_ADD_TEST(ft_tolower);
#endif
#ifdef PART2
	UT_ADD_TEST(ft_memalloc);
	UT_ADD_TEST(ft_memdel);
	UT_ADD_TEST(ft_strnew);
	UT_ADD_TEST(ft_strdel);
	UT_ADD_TEST(ft_strclr);
	UT_ADD_TEST(ft_striter);
	UT_ADD_TEST(ft_striteri);
	UT_ADD_TEST(ft_strmap);
	UT_ADD_TEST(ft_strmapi);
	UT_ADD_TEST(ft_strequ);
	UT_ADD_TEST(ft_strnequ);
	UT_ADD_TEST(ft_strsub);
	UT_ADD_TEST(ft_strjoin);
	UT_ADD_TEST(ft_strtrim);
	UT_ADD_TEST(ft_strsplit);
	UT_ADD_TEST(ft_itoa);
	UT_ADD_TEST(ft_putchar);
	UT_ADD_TEST(ft_putstr);
	UT_ADD_TEST(ft_putendl);
	UT_ADD_TEST(ft_putnbr);
	UT_ADD_TEST(ft_putchar_fd);
	UT_ADD_TEST(ft_putstr_fd);
	UT_ADD_TEST(ft_putendl_fd);
	UT_ADD_TEST(ft_putnbr_fd);
#endif
#ifdef	BONUS
	UT_ADD_TEST(ft_lstnew);
	UT_ADD_TEST(ft_lstdelone);
	UT_ADD_TEST(ft_lstdel);
	UT_ADD_TEST(ft_lstadd);
	UT_ADD_TEST(ft_lstiter);
	UT_ADD_TEST(ft_lstmap);
#endif

#ifdef TEST_ft_JUSCHAEF
	UT_ADD_TEST(ft_putnendl);
	UT_ADD_TEST(ft_putnstr);
	UT_ADD_TEST(ft_sqrt);
	UT_ADD_TEST(ft_power);
	UT_ADD_TEST(ft_sort_int_table);
#endif

<MAIN_TEST_BLOCK>
/*
#ifdef TEST_ft_replace_char
UT_ADD_TEST(ft_replace_char);
#endif

#ifdef TEST_ft_isspace
UT_ADD_TEST(ft_isspace);
#endif

#ifdef TEST_ft_memswap
	UT_ADD_TEST(ft_memswap);
#endif

#ifdef TEST_ft_swap
	UT_ADD_TEST(ft_swap);
#endif

#ifdef TEST_ft_isblank
	UT_ADD_TEST(ft_isblank);
#endif

#ifdef TEST_ft_memdup
	UT_ADD_TEST(ft_memdup);
#endif

#ifdef TEST_ft_strrev
	UT_ADD_TEST(ft_strrev);
#endif

#ifdef TEST_ft_strtrimc
	UT_ADD_TEST(ft_strtrimc);
#endif

#ifdef TEST_ft_islower
	UT_ADD_TEST(ft_islower);
#endif

#ifdef TEST_ft_isupper
	UT_ADD_TEST(ft_isupper);
#endif

#ifdef TEST_ft_ispunct
	UT_ADD_TEST(ft_ispunct);
#endif

#ifdef TEST_ft_abs
	UT_ADD_TEST(ft_abs);
#endif

#ifdef TEST_ft_strcapitalize
	UT_ADD_TEST(ft_strcapitalize);
#endif

#ifdef TEST_ft_factorial
	UT_ADD_TEST(ft_factorial);
#endif

#ifdef TEST_ft_strupcase
	UT_ADD_TEST(ft_strupcase);
#endif

#ifdef TEST_ft_strlowcase
	UT_ADD_TEST(ft_strlowcase);
#endif

#ifdef TEST_ft_rotone
	UT_ADD_TEST(ft_rotone);
#endif

#ifdef TEST_ft_nrot
	UT_ADD_TEST(ft_nrot);
#endif

#ifdef TEST_ft_printable_rotone
	UT_ADD_TEST(ft_printable_rotone);
#endif

#ifdef TEST_ft_ptrswap
	UT_ADD_TEST(ft_ptrswap);
#endif
*/
	UT_RUN_ALL_TESTS();
	return (0);
}

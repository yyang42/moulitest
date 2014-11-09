#include "unit_test.h"
#include "libft.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc/malloc.h>

/* Uncomment this if you have the functions */

/* #define PART1 */
/* #define PART2 */
/* #define BONUS */
/* #define EXTRA_YYANG */

#ifdef PART1

UT_TEST(ft_memset)
{
	char	b1[100], b2[100];

	ft_memset(b1, 42, 100);
	memset(b2, 42, 100);
	UT_ASSERT_EQ(memset(b1, 99, 0), ft_memset(b1, 99, 0));
	UT_ASSERT_EQ(memcmp(b1, b2, 100), 0);
	b1[0] = 1;
	ft_memset(b1, 0, 0);
	UT_ASSERT_EQ(b1[0], 1);
}

UT_TEST(ft_bzero)
{
	char	b1[10], b2[10];

	bzero(b1, 10);
	ft_bzero(b2, 10);
	UT_ASSERT_EQ(memcmp(b1, b2, 10), 0);
	b1[0] = 1;
	ft_bzero(b1, 0);
	UT_ASSERT_EQ(b1[0], 1);
}

UT_TEST(ft_memcpy)
{
	char	b1[100], b2[100];

	memset(b1, 33, 100);
	memset(b2, 63, 100);
	ft_memcpy(b1, b2, 100);
	UT_ASSERT_EQ(memcmp(b1, b2, 100), 0);
	UT_ASSERT_EQ(b1, ft_memcpy(b1, b2, 0));
}

UT_TEST(ft_memccpy)
{
	char	buf1[] = "Ceci est un test.";
	char	buf2[200];
	void	*p1, *p2;

	p1 = memccpy(buf2, buf1, 'i', 10);
	p2 = ft_memccpy(buf2, buf1, 'i', 10);
	UT_ASSERT_EQ(p1, p2);
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 'k', 5), 0);
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 0, 0), memccpy(buf2, buf1, 0, 0));
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 0, sizeof(buf1)), memccpy(buf2, buf1, 0, sizeof(buf1)));
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 'C', 10), buf2 + 1);
}

UT_TEST(ft_memmove)
{
	char	test[] = "abcdef";

	ft_memmove(test + 1, test, 5);
	ft_memmove(test + 1, test, 0);
	UT_ASSERT_EQ(strcmp(test, "aabcde"), 0);
}

UT_TEST(ft_memchr)
{
	char	test[] = "abcdef";

	UT_ASSERT_EQ(ft_memchr(test, 'a', 5), test);
	UT_ASSERT_EQ(ft_memchr(test, 'c', 5), test + 2);
	UT_ASSERT_EQ(ft_memchr(test, '\0', 7), memchr(test, '\0', 7));
	UT_ASSERT_EQ(ft_memchr(test, 'z', 6), 0);
}

UT_TEST(ft_memcmp)
{
	char	*t = "ab\0ab";

	UT_ASSERT_EQ(ft_memcmp(t, t, 5), 0);
	UT_ASSERT_NEQ(ft_memcmp(t, "abcab", 5) ,0);
	UT_ASSERT(ft_memcmp("aaa", "aab", 4) < 0);
	UT_ASSERT_EQ(ft_memcmp("aww", "bpp", 0), 0);
	UT_ASSERT(ft_memcmp("\200", "\0", 1) > 0);
}

UT_TEST(ft_strlen)
{
	UT_ASSERT_EQ(ft_strlen("chat"), strlen("chat"));
	UT_ASSERT_EQ(ft_strlen(""), strlen(""));
	UT_ASSERT_EQ(ft_strlen("aaa\0aaa"), strlen("aaa\0aaa"));
}

UT_TEST(ft_strdup)
{
	char	*c;

	c = "AbC";
	UT_ASSERT_EQ(strcmp(ft_strdup("aaaaa"), "aaaaa"), 0);
	UT_ASSERT_EQ(strcmp(ft_strdup(""), ""), 0);
	UT_ASSERT_NEQ(c, ft_strdup(c));
}

UT_TEST(ft_strcpy)
{
	char	buf[6];

	bzero(buf, 6);
	ft_strcpy(buf, "abcde");
	UT_ASSERT_EQ(strcmp(buf, "abcde"), 0);
	ft_strcpy(buf, "abc");
	UT_ASSERT_EQ(strcmp(buf, "abc"), 0);
}

UT_TEST(ft_strncpy)
{
	char	buf[6];

	memset(buf, 33, 6);
	ft_strncpy(buf, "abc", 6);
	UT_ASSERT_EQ(memcmp(buf, "abc\0\0", 6), 0);
	ft_strncpy(buf, "abcdefghi", 6);
	UT_ASSERT_EQ(memcmp(buf, "abcdefghi", 6), 0);
}

UT_TEST(ft_strcat)
{
	char	buf[9];

	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");
	UT_ASSERT_EQ(strcmp(buf, "Bonjour."), 0);
	UT_ASSERT_EQ(buf, ft_strcat(buf, ""));
}

UT_TEST(ft_strncat)
{
	char	buf[20];

	strcpy(buf, "To be ");
	ft_strncat(buf, "or not to be", 6);
	UT_ASSERT_EQ(strcmp(buf, "To be or not"), 0);
	ft_strncat(buf, "efefef", 0);
	UT_ASSERT_EQ(strcmp(buf, "To be or not"), 0);
	UT_ASSERT_EQ(buf, ft_strncat(buf, "", 0));
}

UT_TEST(ft_strlcat)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "abc");
	ft_strlcat(buf, "abcdefghijklmnop", 10);
	UT_ASSERT_EQ(strcmp(buf, "abcabcdef"), 0);
	UT_ASSERT_EQ(ft_strlcat(buf, "abcd", 2), 6);
	bzero(buf, 10);
	UT_ASSERT_EQ(ft_strlcat(buf, "abc", 10), 3);
	UT_ASSERT_EQ(ft_strlcat(buf, "def", 10), 6);
	bzero(buf, 10);
	memset(buf, 'a', 10);
	UT_ASSERT_EQ(ft_strlcat(buf, "ccc", 10), 13);
}

UT_TEST(ft_strchr)
{
	char	buf[] = "Je suis un poisson.";

	UT_ASSERT_EQ(strchr(buf, 'p'), ft_strchr(buf, 'p'));
	UT_ASSERT_EQ(strchr(buf, 0), ft_strchr(buf, 0));
	UT_ASSERT_EQ(ft_strchr(buf, 'J'), buf);
	UT_ASSERT_EQ(ft_strchr(buf, 'z'), 0);
}

UT_TEST(ft_strrchr)
{
	char	buf[] = "abcdedcba";

	UT_ASSERT_EQ(strrchr(buf, 'a'), ft_strrchr(buf, 'a'));
	UT_ASSERT_EQ(strrchr(buf, 0), ft_strrchr(buf, 0));
	UT_ASSERT_EQ(ft_strrchr(buf, 'z'), 0);
	buf[5] = 0;
	UT_ASSERT_EQ(ft_strrchr(buf, 'a'), buf);
}

UT_TEST(ft_strstr)
{
	char	buf[] = "Ceci n'est pas une pipe.";

	UT_ASSERT_EQ(strstr(buf, "une"), ft_strstr(buf, "une"));
	UT_ASSERT_EQ(strstr(buf, "C"), ft_strstr(buf, "C"));
	UT_ASSERT_EQ(strstr(buf, "."), ft_strstr(buf, "."));
	UT_ASSERT_EQ(strstr(buf, ""), ft_strstr(buf, ""));
	UT_ASSERT_EQ(strstr(buf, "aaaaa"), ft_strstr(buf, "aaaaa"));
	UT_ASSERT_EQ(ft_strstr(buf, "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"), NULL);
}

UT_TEST(ft_strnstr)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
	UT_ASSERT_EQ(strnstr(buf, "9", 3), ft_strnstr(buf, "9", 3));
	UT_ASSERT_EQ(ft_strnstr(buf, "", 6), buf);
	UT_ASSERT_EQ(ft_strnstr(buf, "deux", 5), strnstr(buf, "deux", 5));
	UT_ASSERT_EQ(ft_strnstr(buf, "9", 10), strnstr(buf, "9", 10));
	UT_ASSERT_EQ(ft_strnstr(buf, "9", 8), strnstr(buf, "9", 8));
	buf[9] = '6';
	UT_ASSERT_EQ(strnstr(buf, "cinq", 10), ft_strnstr(buf, "cinq", 10));
	UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
	UT_ASSERT_EQ(strnstr(buf, "9682", 10), ft_strnstr(buf, "9682", 10));
	UT_ASSERT_EQ(strnstr(buf, "6", 10), ft_strnstr(buf, "6", 10));
	buf[1] = 0;
	UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
}

UT_TEST(ft_strcmp)
{
	UT_ASSERT_EQ(ft_strcmp("abc", "abc"), 0);
	UT_ASSERT(ft_strcmp("abc", "abd") < 0);
	UT_ASSERT(ft_strcmp("\200", "\0") > 0);
	UT_ASSERT_NEQ(ft_strcmp("a", "abcde"), 0);
}

UT_TEST(ft_strncmp)
{
	UT_ASSERT(ft_strncmp("\200", "\0", 1) > 0);
	UT_ASSERT_EQ(ft_strncmp("abc", "abcde", 3), 0);
	UT_ASSERT_EQ(ft_strncmp("abc", "abc\0defg", 100), 0);
	UT_ASSERT_NEQ(ft_strncmp("ab\0cde", "abcc\0e", 20), 0);
}

UT_TEST(ft_atoi)
{
	UT_ASSERT_EQ(ft_atoi(" -sfecf"), 0);
	UT_ASSERT_EQ(ft_atoi("+2798"), 2798);
	UT_ASSERT_EQ(ft_atoi("  \t\n  \r\r\v\f-899"), -899);
	UT_ASSERT_EQ(ft_atoi("+0089"), 89);
	UT_ASSERT_EQ(ft_atoi("-2147483648"), -2147483648);
	UT_ASSERT_EQ(ft_atoi("a56"), 0);
	UT_ASSERT_EQ(ft_atoi("    555 5555555555555555"), 555);
	UT_ASSERT_EQ(ft_atoi("      --s8"), 0);
	UT_ASSERT_EQ(ft_atoi("0001020304"), 1020304);
}

UT_TEST(ft_isalpha)
{
	UT_ASSERT_NEQ(ft_isalpha('a'), 0);
	UT_ASSERT_EQ(ft_isalpha('a' + 0x100), 0);
	UT_ASSERT_EQ(ft_isalpha('2'), 0);
	UT_ASSERT_NEQ(ft_isalpha('Z'), 0);
	UT_ASSERT_NEQ(ft_isalpha('t'), 0);
}

UT_TEST(ft_isdigit)
{
	UT_ASSERT_EQ(ft_isdigit(0), 0);
	UT_ASSERT_NEQ(ft_isdigit('8'), 0);
	UT_ASSERT_EQ(ft_isdigit('8' + 0x100), 0);
}

UT_TEST(ft_isalnum)
{
	UT_ASSERT_EQ(ft_isalnum(' '), 0);
	UT_ASSERT_NEQ(ft_isalnum('6'), 0);
	UT_ASSERT_NEQ(ft_isalnum('Z'), 0);
	UT_ASSERT_EQ(ft_isalnum('5' + 0x100), 0);
	UT_ASSERT_EQ(ft_isalnum('5' + 0x100), 0);
	UT_ASSERT_EQ(ft_isalnum('5' + 0x100), 0);
	UT_ASSERT_EQ(ft_isalnum('5' + 0x100), 0);
}

UT_TEST(ft_isascii)
{
	UT_ASSERT_EQ(ft_isascii(200), 0);
	UT_ASSERT_NEQ(ft_isascii(0), 0);
	UT_ASSERT_NEQ(ft_isascii(127), 0);
}

UT_TEST(ft_isprint)
{
	UT_ASSERT_EQ(ft_isprint(0), 0);
	UT_ASSERT_EQ(ft_isprint(127), 0);
	UT_ASSERT_NEQ(ft_isprint(' '), 0);
	UT_ASSERT_NEQ(ft_isprint('a'), 0);
	UT_ASSERT_NEQ(ft_isprint(126), 0);
}

UT_TEST(ft_toupper)
{
	UT_ASSERT_EQ(ft_toupper('a'), 'A');
	UT_ASSERT_EQ(ft_toupper(12345), 12345);
	UT_ASSERT_EQ(ft_toupper(' '), ' ');
	UT_ASSERT_EQ(ft_toupper('Z'), 'Z');
}

UT_TEST(ft_tolower)
{
	UT_ASSERT_EQ(ft_tolower('T'), 't');
	UT_ASSERT_EQ(ft_tolower(99999), 99999);
	UT_ASSERT_EQ(ft_tolower('e'), 'e');
}

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

#ifdef EXTRA_YYANG
/*
UT_TEST(ft_memdup)
{
	char	*c;

	c = "AbC";
	UT_ASSERT_EQ(strcmp(ft_memdup("aaaaa", 6), "aaaaa"), 0);
	UT_ASSERT_EQ(strcmp(ft_memdup("", 1), ""), 0);
	UT_ASSERT_NEQ(c, ft_memdup(c, 4));
}
*/
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

/*
UT_TEST(ft_ptrswap)
{
	int		was_1 = 1;
	int		was_2 = 2;
	char	was_a = 'a';
	char	was_b = 'b';
	int		*ptr_1 = &was_1;
	int		*ptr_2 = &was_2;
	char	*ptr_a = &was_a;
	char	*ptr_b = &was_b;

	ft_ptrswap(&ptr_1, &ptr_2);
	ft_ptrswap(&ptr_a, &ptr_b);
	UT_ASSERT(*ptr_1 == 2);
	UT_ASSERT(*ptr_2 == 1);
	UT_ASSERT(*ptr_a == 'b');
	UT_ASSERT(*ptr_b == 'a');
}

UT_TEST(ft_memswap)
{
	char	was_a = 'a';
	char	was_b = 'b';
	int		was_1 = 1;
	int		was_2 = 2;
	char	was_toto[] = "toto";
	char	was_tata[] = "tata";

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
}

UT_TEST(ft_strlcpy)
{
	char	buf[10];
	size_t	output;

	output = ft_strlcpy(buf, "1234567890", 10);
	UT_ASSERT_EQ(strcmp(buf, "123456789"), 0);
	UT_ASSERT_EQ(output, 10);
	output = ft_strlcpy(buf, "12345", 10);
	UT_ASSERT_EQ(strcmp(buf, "12345"), 0);
	UT_ASSERT_EQ(output, 5);
	output = ft_strlcpy(buf, "1234567890", 0);
	UT_ASSERT_EQ(strcmp(buf, "12345"), 0);
	UT_ASSERT_EQ(output, 10);
}
*/

UT_TEST(ft_strtrimc)
{
	UT_ASSERT_EQ(strcmp(ft_strtrimc("*****AAA*****BBB*****", '*'), "AAA*****BBB"), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrimc("**********", '*'), ""), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrimc("", '*'), ""), 0);
	UT_ASSERT_EQ(strcmp(ft_strtrimc("abc", '*'), "abc"), 0);
}

#endif

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
#ifdef	EXTRA_YYANG
	UT_ADD_TEST(ft_strrev);
	UT_ADD_TEST(ft_strtrimc);
/*
	UT_ADD_TEST(ft_memdup);
	UT_ADD_TEST(ft_ptrswap);
	UT_ADD_TEST(ft_memswap);
	UT_ADD_TEST(ft_strlcpy);
*/
#endif
	UT_RUN_ALL_TESTS();
	return (0);
}

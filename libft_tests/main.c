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
	UT_ASSERT_EQ(ft_memcmp("aab", "aac", 2), 0);
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
	/* No need to test for NULL value
	**
	** ft_strcmp(NULL, NULL)
	**
	** The standard strcmp function return this error:
	** error: null argument where non-null required
	*/
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
	UT_ASSERT_EQ(ft_atoi(" -sfecf"), atoi(" -sfecf"));
	UT_ASSERT_EQ(ft_atoi(""), atoi(""));
	UT_ASSERT_EQ(ft_atoi("+2798"), atoi("+2798"));
	UT_ASSERT_EQ(ft_atoi("  \t\n  \r\r\v\f-899"), atoi("  \t\n  \r\r\v\f-899"));
	UT_ASSERT_EQ(ft_atoi("+0089"), atoi("+0089"));
	UT_ASSERT_EQ(ft_atoi("-2147483648"), atoi("-2147483648"));
	UT_ASSERT_EQ(ft_atoi("2147483647"), atoi("2147483647"));
	UT_ASSERT_EQ(ft_atoi("2147483648"), atoi("2147483648"));
	UT_ASSERT_EQ(ft_atoi("9223372036854775807"), atoi("9223372036854775807"));
	UT_ASSERT_EQ(ft_atoi("9223372036854775806"), atoi("9223372036854775806"));
	UT_ASSERT_EQ(ft_atoi("9223372036854775808"), atoi("9223372036854775808"));
	UT_ASSERT_EQ(ft_atoi("-9223372036854775807"), atoi("-9223372036854775807"));
	UT_ASSERT_EQ(ft_atoi("-9223372036854775806"), atoi("-9223372036854775806"));
	UT_ASSERT_EQ(ft_atoi("-9223372036854775808"), atoi("-9223372036854775808"));
	UT_ASSERT_EQ(ft_atoi("a56"), atoi("a56"));
	UT_ASSERT_EQ(ft_atoi("    555 5555555555555555")
				 , atoi("    555 5555555555555555"));
	UT_ASSERT_EQ(ft_atoi("      --s8"), atoi("      --s8"));
	UT_ASSERT_EQ(ft_atoi("0001020304"), atoi("0001020304"));
	UT_ASSERT_EQ(ft_atoi("000000000000000110"), atoi("000000000000000110"));
	UT_ASSERT_EQ(ft_atoi("-153"), atoi("-153"));
	UT_ASSERT_EQ(ft_atoi("+132"), atoi("+132"));
	UT_ASSERT_EQ(ft_atoi("++876"), atoi("++876"));
	UT_ASSERT_EQ(ft_atoi("--132"), atoi("--132"));
	UT_ASSERT_EQ(ft_atoi("dwbk "), atoi("dwbk "));
	UT_ASSERT_EQ(ft_atoi(" 1"), atoi(" 1"));
	UT_ASSERT_EQ(ft_atoi("42jk "), atoi("42jk "));
	UT_ASSERT_EQ(ft_atoi(" 21"), atoi(" 21"));
	UT_ASSERT_EQ(ft_atoi("     32 "), atoi("     32 "));
	UT_ASSERT_EQ(ft_atoi("\n          42 24"), atoi("\n          42 24"));
	UT_ASSERT_EQ(ft_atoi("1-2"), atoi("1-2"));
	UT_ASSERT_EQ(ft_atoi("4+2"), atoi("4+2"));
	UT_ASSERT_EQ(ft_atoi("  +442"), atoi("  +442"));
	UT_ASSERT_EQ(ft_atoi("  -4232"), atoi("  -4232"));
	UT_ASSERT_EQ(ft_atoi("4,5"), atoi("4,5"));
	UT_ASSERT_EQ(ft_atoi("+"), atoi("+"));
	UT_ASSERT_EQ(ft_atoi("-"), atoi("-"));
	UT_ASSERT_EQ(ft_atoi("-+1"), atoi("-+1"));
	UT_ASSERT_EQ(ft_atoi("+-1"), atoi("+-1"));
	/*
	UT_ASSERT_EQ(ft_atoi("2398472983749236582739823758723469826928374")
				 , atoi("2398472983749236582739823758723469826928374"));
	UT_ASSERT_EQ(ft_atoi("-2398472983749236582739823758723469826928374")
				 , atoi("-2398472983749236582739823758723469826928374"));
	*/
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

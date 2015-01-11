#include <project.h>

static void unittest1(t_test *test)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "abc");
	ft_strlcat(buf, "abcdefghijklmnop", 10);
	mt_assert(strcmp(buf, "abcabcdef") == 0);
	mt_assert(ft_strlcat(buf, "abcd", 2) == 6);
}

static void unittest2(t_test *test)
{
	char	buf[10];

	bzero(buf, 10);
	mt_assert(ft_strlcat(buf, "abc", 10) == 3);
	mt_assert(ft_strlcat(buf, "def", 10) == 6);

}

static void unittest3(t_test *test)
{
	char	buf[10];

	bzero(buf, 10);
	memset(buf, 'a', 10);
	mt_assert(ft_strlcat(buf, "ccc", 10) == 13);

}

static void unittest4(t_test *test)
{
	mt_assert(ft_strlcat(strdup("abc\0\0\0"), "ccc", 0) == strlcat(strdup("abc\0\0\0"), "ccc", 0));
}

static void unittest5(t_test *test)
{
	mt_assert(ft_strlcat(strdup("abc\0\0\0"), "ccc", 1) == strlcat(strdup("abc\0\0\0"), "ccc", 1));
}

static void unittest6(t_test *test)
{
	mt_assert(ft_strlcat(strdup("abc\0\0\0"), "ccc", 6) == strlcat(strdup("abc\0\0\0"), "ccc", 6));
}

static void unittest7(t_test *test)
{
	mt_assert(ft_strlcat(strdup("abc\0\0\0"), "ccc", 10) == strlcat(strdup("abc\0\0\0"), "ccc", 10));
}

void	suite_00_part1_ft_strlcat(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
	SUITE_ADD_TEST(suite, unittest4);
	SUITE_ADD_TEST(suite, unittest5);
	SUITE_ADD_TEST(suite, unittest6);
	SUITE_ADD_TEST(suite, unittest7);
}

#include <project.h>
#include <string.h>

static void unittest1(t_test *test)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	mt_assert(strcmp(ft_strnstr(buf, "deux", 10), "deux 9") == 0);
	mt_assert(ft_strnstr(buf, "9", 3) == NULL);
	mt_assert(strcmp(ft_strnstr(buf, "", 6), buf) == 0);
	mt_assert(ft_strnstr(buf, "deux", 5) == NULL);
	mt_assert(strcmp(ft_strnstr(buf, "9", 10), "9") == 0);
	mt_assert(ft_strnstr(buf, "9", 8) == NULL);
}

static void unittest2(t_test *test)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	buf[9] = '6';
	mt_assert(strcmp(ft_strnstr(buf, "deux", 10), "deux 96") == 0);
	mt_assert(ft_strnstr(buf, "cinq", 10) == NULL);
	mt_assert(ft_strnstr(buf, "9682", 10) == NULL);
	mt_assert(strcmp(ft_strnstr(buf, "6", 10), "6") == 0);
}

static void unittest3(t_test *test)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	buf[9] = '6';
	buf[1] = 0;
	mt_assert(ft_strnstr(buf, "deux", 10) == 0);
}

static void unittest4(t_test *test)
{
	char	buf2[] = "ozarabozaraboze123";

	mt_assert(strcmp(ft_strnstr(buf2, "ozaraboze", 15), "ozaraboze123") == 0);
}

void	suite_00_part1_ft_strnstr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
	SUITE_ADD_TEST(suite, unittest4);
}

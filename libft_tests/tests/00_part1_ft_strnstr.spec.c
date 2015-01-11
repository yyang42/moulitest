#include <project.h>

static void unittest1(t_test *test)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	mt_assert(strnstr(buf, "deux", 10) == ft_strnstr(buf, "deux", 10));
	mt_assert(strnstr(buf, "9", 3) == ft_strnstr(buf, "9", 3));
	mt_assert(ft_strnstr(buf, "", 6) == buf);
	mt_assert(ft_strnstr(buf, "deux", 5) == strnstr(buf, "deux", 5));
	mt_assert(ft_strnstr(buf, "9", 10) == strnstr(buf, "9", 10));
	mt_assert(ft_strnstr(buf, "9", 8) == strnstr(buf, "9", 8));
}

static void unittest2(t_test *test)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	buf[9] = '6';
	mt_assert(strnstr(buf, "cinq", 10) == ft_strnstr(buf, "cinq", 10));
	mt_assert(strnstr(buf, "deux", 10) == ft_strnstr(buf, "deux", 10));
	mt_assert(strnstr(buf, "9682", 10) == ft_strnstr(buf, "9682", 10));
	mt_assert(strnstr(buf, "6", 10) == ft_strnstr(buf, "6", 10));
}

static void unittest3(t_test *test)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	buf[9] = '6';
	buf[1] = 0;
	mt_assert(strnstr(buf, "deux", 10) == ft_strnstr(buf, "deux", 10));
}

static void unittest4(t_test *test)
{
	char	buf2[] = "ozarabozaraboze";

	mt_assert(strnstr(buf2, "ozaraboze", 15) == ft_strnstr(buf2, "ozaraboze", 15));
}

void	suite_00_part1_ft_strnstr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
	SUITE_ADD_TEST(suite, unittest4);
}

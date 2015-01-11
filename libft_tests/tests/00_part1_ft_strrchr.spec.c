#include <project.h>

static char	buf[] = "abcdedcba";

static void unittest1(t_test *test)
{
	mt_assert(strrchr(buf, 'a') == ft_strrchr(buf, 'a'));
}

static void unittest2(t_test *test)
{
	mt_assert(strrchr(buf, 0) == ft_strrchr(buf, 0));
}

static void unittest3(t_test *test)
{
	mt_assert(ft_strrchr(buf, 'z') == 0);
}

static void unittest4(t_test *test)
{
	char	buf2[] = "abcd";

	mt_assert(ft_strrchr(buf2, 'a') == buf2);
}

void	suite_00_part1_ft_strrchr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
	SUITE_ADD_TEST(suite, unittest4);
}

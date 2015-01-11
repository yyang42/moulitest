#include <project.h>

static void unittest1(t_test *test)
{
	char	buf[6];

	memset(buf, 33, 6);
	ft_strncpy(buf, "abc", 6);
	mt_assert(memcmp(buf, "abc\0\0", 6) == 0);
}

static void unittest2(t_test *test)
{
	char	buf[6];

	memset(buf, 33, 6);
	ft_strncpy(buf, "abcdefghi", 6);
	mt_assert(memcmp(buf, "abcdefghi", 6) == 0);
}

void	suite_00_part1_ft_strncpy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
}

#include <project.h>

static void unittest1(t_test *test)
{
	mt_assert(ft_memcmp(ft_strdup("ab\0ab"), ft_strdup("ab\0ab"), 5) == 0);

}

static void unittest2(t_test *test)
{
	mt_assert(ft_memcmp(ft_strdup("ab\0ab"), "abcab", 5) != 0);
}

static void unittest3(t_test *test)
{
	mt_assert(ft_memcmp("aaa", "aab", 4) < 0);
}

static void unittest4(t_test *test)
{
	mt_assert(ft_memcmp("aab", "aac", 2) == 0);
}

static void unittest5(t_test *test)
{
	mt_assert(ft_memcmp("aww", "bpp", 0) == 0);
}

static void unittest6(t_test *test)
{
	mt_assert(ft_memcmp("\200", "\0", 1) > 0);
}

void	suite_00_part1_ft_memcmp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
	SUITE_ADD_TEST(suite, unittest4);
	SUITE_ADD_TEST(suite, unittest5);
	SUITE_ADD_TEST(suite, unittest6);
}

#include <project.h>

static void unittest1(t_test *test)
{
	char	testA1[] = "abcdef";
	char	testA2[] = "abcdef";

	ft_memmove(testA1 + 1, testA1, 5);
	ft_memmove(testA1 + 1, testA1, 0);
	memmove(testA2 + 1, testA2, 5);
	memmove(testA2 + 1, testA2, 0);
	mt_assert(strcmp(testA1, "aabcde") == 0);
	mt_assert(strcmp(testA1, testA2) == 0);
}

static void unittest2(t_test *test)
{
	char	testB1[] = "abcdef";
	char	testB2[] = "abcdef";

	ft_memmove(testB1, testB1 + 1, 5);
	ft_memmove(testB1, testB1 + 1, 0);
	memmove(testB2, testB2 + 1, 5);
	memmove(testB2, testB2 + 1, 0);
	mt_assert(strcmp(testB1, "bcdeff") == 0);
	mt_assert(strcmp(testB1, testB2) == 0);
}

void	suite_00_part1_ft_memmove(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
}

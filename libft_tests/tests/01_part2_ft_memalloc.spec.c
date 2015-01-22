#include <project.h>
#include <limits.h>

static void simple_test(t_test *test)
{
	void	*mem1, *mem2;

	mem1 = malloc(100);
	bzero(mem1, 100);
	mem2 = ft_memalloc(100);

	mt_assert(!!mem1 && !!mem2);
	mt_assert(mem1 && mem2 && memcmp(mem1, mem2, 100) == 0);
}

static void test_too_big_size(t_test *test)
{
	mt_assert(ft_memalloc(ULONG_MAX) == NULL);
}

void	suite_01_part2_ft_memalloc(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_too_big_size);
}

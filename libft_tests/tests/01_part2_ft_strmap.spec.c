#include <project.h>

static void test1(t_test *test)
{
	char	*src;
	char	*dst;

	src = strdup("abcde");
	dst = ft_strmap(src, map_test);

	free(src); src = NULL;

	mt_assert(strcmp(dst, "bcdef") == 0);
}

void	suite_01_part2_ft_strmap(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
}

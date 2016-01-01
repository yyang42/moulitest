#include <project.h>

static void test1(t_test *test)
{
	char	*src;
	char	*dst;

	src = strdup("eeeee");
	dst = ft_strmapi(src, mapi_test);

	free(src);
	src = NULL;

	mt_assert(strcmp(dst, "edcba") == 0);
}

void	suite_01_part2_ft_strmapi(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
}

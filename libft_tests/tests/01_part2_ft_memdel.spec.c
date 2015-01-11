#include <project.h>

static void simple_test(t_test *test)
{
	void	*mem;

	mem = malloc(2000);
	ft_memdel(&mem);
	mt_assert(mem == NULL);
}

void	suite_01_part2_ft_memdel(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

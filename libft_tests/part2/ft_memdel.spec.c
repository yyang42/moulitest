#include "project.h"

UT_TEST(ft_memdel)
{
	void	*mem;

	mem = malloc(2000);
	ft_memdel(&mem);
	UT_ASSERT_W(mem == NULL);

	/* test edge cases */
	// void	*mem2;
	// mem2 = NULL;
	// ft_memdel(NULL);
	// ft_memdel(&mem2);
}

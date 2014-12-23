#include "project.h"

UT_TEST(ft_memalloc)
{
	void	*mem1, *mem2;

	mem1 = malloc(100);
	bzero(mem1, 100);
	mem2 = ft_memalloc(100);

	UT_ASSERT(memcmp(mem1, mem2, 100) == 0);
	UT_ASSERT(ft_memalloc((size_t)-1) == NULL);
}

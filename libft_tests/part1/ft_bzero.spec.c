#include "project.h"

UT_TEST(ft_bzero)
{
	char	b1[10], b2[10];

	bzero(b1, 10);
	ft_bzero(b2, 10);
	UT_ASSERT_EQ(memcmp(b1, b2, 10), 0);
	b1[0] = 1;
	ft_bzero(b1, 0);
	UT_ASSERT_EQ(b1[0], 1);

	/* test edge cases */
	bzero(NULL, 0);
	ft_bzero(NULL, 0);
}

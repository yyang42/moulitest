#include "project.h"

UT_TEST(ft_memset)
{
	char	b1[100], b2[100];

	ft_memset(b1, 42, 100);
	memset(b2, 42, 100);
	UT_ASSERT_EQ(memset(b1, 99, 0), ft_memset(b1, 99, 0));
	UT_ASSERT_EQ(memcmp(b1, b2, 100), 0);
	b1[0] = 1;
	ft_memset(b1, 0, 0);
	UT_ASSERT_EQ(b1[0], 1);

	UT_ASSERT(memcmp(memset(strdup("abcd"), 'A', 5), ft_memset(strdup("abcd"), 'A', 5), 5) == 0);

	/* test edge cases */
	/*ft_memset(0, 0, 0);
	ft_memset(0, 'A', 0);
	*/
	UT_ASSERT(memcmp(memset(strdup("abcd"), 0, 0), ft_memset(strdup("abcd"), 0, 0), 5) == 0);
}

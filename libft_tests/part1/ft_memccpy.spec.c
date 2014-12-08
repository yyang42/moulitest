#include "project.h"

UT_TEST(ft_memccpy)
{
	char	buf1[] = "Ceci est un test.";
	char	buf2[200];
	void	*p1, *p2;

	p1 = memccpy(buf2, buf1, 'i', 10);
	p2 = ft_memccpy(buf2, buf1, 'i', 10);
	UT_ASSERT_EQ(p1, p2);
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 'k', 5), 0);
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 0, 0), memccpy(buf2, buf1, 0, 0));
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 0, sizeof(buf1)), memccpy(buf2, buf1, 0, sizeof(buf1)));
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 'C', 10), buf2 + 1);

	char dest[] = "abcdefghijklmnopqrstuvwxyz";
	UT_ASSERT_EQ(ft_memccpy(dest, strdup("test\200string"), '\200', 12),
		memccpy(dest, strdup("test\200string"), '\200', 12));
}

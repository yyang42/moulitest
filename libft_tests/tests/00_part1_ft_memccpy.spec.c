#include <project.h>

static void unittest(t_test *test)
{
	char	buf1[] = "Ceci est un test.";
	char	buf2[200];
	void	*p1, *p2;

	p1 = memccpy(buf2, buf1, 'i', 10);
	p2 = ft_memccpy(buf2, buf1, 'i', 10);
	mt_assert(p1 == p2);
	mt_assert(ft_memccpy(buf2, buf1, 'k', 5) == 0);
	mt_assert(ft_memccpy(buf2, buf1, 0, 0) == memccpy(buf2, buf1, 0, 0));
	mt_assert(ft_memccpy(buf2, buf1, 0, sizeof(buf1)) == memccpy(buf2, buf1, 0, sizeof(buf1)));
	mt_assert(ft_memccpy(buf2, buf1, 'C', 10) == buf2 + 1);

	char dest[] = "abcdefghijklmnopqrstuvwxyz";
	mt_assert(ft_memccpy(dest, strdup("test\200string"), '\200', 12) ==
		memccpy(dest, strdup("test\200string"), '\200', 12));
}

void	suite_00_part1_ft_memccpy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest);
}

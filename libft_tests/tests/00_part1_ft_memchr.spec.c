#include <project.h>

static void unittest(t_test *test)
{

	mt_assert(ft_memchr("abcdef", 'a', 5) == memchr("abcdef", 'a', 5));
	mt_assert(ft_memchr("abcdef", 'c', 5) == memchr("abcdef", 'c', 5));
	mt_assert(ft_memchr("abcdef", '\0', 7) == memchr("abcdef", '\0', 7));
	mt_assert(ft_memchr("abcdef", 'z', 6) == memchr("abcdef", 'z', 6));
	mt_assert(ft_memchr("abcdef", 999, 6) == memchr("abcdef", 999, 6));

	/* Barbarian test from Qperez !! */
	char			ctab[11];
	int				itab[11];
	unsigned long	ltab[11];
	size_t			j;
	int				i;

	i = -300;
	ft_memchr(NULL, 0, 0);
	while (i < 300)
	{
		j = 0;
		while (j < 11)
		{
			ctab[j] = (char)rand();
			itab[j] = rand();
			ltab[j] = (unsigned long)rand() * 10000;
			j++;
		}
		if ((memchr(ctab, i, sizeof(ctab)) != ft_memchr(ctab, i, sizeof(ctab)))
			|| ((memchr(itab, i, sizeof(itab)) != ft_memchr(itab, i, sizeof(itab))))
			|| (memchr(ltab, i, sizeof(ltab)) != ft_memchr(ltab, i, sizeof(ltab))))
		{
			mt_assert(!"Unsigned char problem?");
			break;
		}
		++i;
	}
/*
	ft_memchr(NULL, 0, 0);
	ft_memchr(NULL, 0, 10);
	ft_memchr(NULL, -10, 10);
*/
}

void	suite_00_part1_ft_memchr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest);
}

#include "project.h"

UT_TEST(ft_strsub)
{
	char	*str = "Un jour je serai, le meilleur dresseur !";

	UT_ASSERT_EQ(ft_strsub(str, 0, (size_t)-10), NULL);
	UT_ASSERT_EQ(strcmp(ft_strsub(str, 8, 8), "je serai"), 0);
	UT_ASSERT_EQ(strcmp(ft_strsub(str, 0, 0), ""), 0);
}

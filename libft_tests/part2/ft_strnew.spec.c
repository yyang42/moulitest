#include "project.h"

UT_TEST(ft_strnew)
{
	char	*str;
	char	*t;

	str = ft_strnew(0);
	UT_ASSERT_NEQ(str, NULL);
	str = ft_strnew(100);
	t = malloc(101);
	bzero(t, 101);
	UT_ASSERT_EQ(memcmp(str, t, 101), 0);
	UT_ASSERT_NEQ(ft_strnew(0), 0);
	UT_ASSERT_EQ(ft_strnew((size_t)-10), 0);
}

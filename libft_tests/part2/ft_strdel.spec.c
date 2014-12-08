#include "project.h"

UT_TEST(ft_strdel)
{
	char	*str;

	str = malloc(123);
	ft_strdel(&str);
	UT_ASSERT_EQ(str, NULL);
}

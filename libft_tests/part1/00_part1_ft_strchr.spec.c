#include "project.h"

UT_TEST(ft_strchr)
{
	char	buf[] = "Je suis un poisson.";

	UT_ASSERT_EQ(strchr(buf, 'p'), ft_strchr(buf, 'p'));
	UT_ASSERT_EQ(strchr(buf, 0), ft_strchr(buf, 0));
	UT_ASSERT_EQ(ft_strchr(buf, 'J'), buf);
	UT_ASSERT_EQ(ft_strchr(buf, 'z'), 0);
}

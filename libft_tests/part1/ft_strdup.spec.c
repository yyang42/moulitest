#include "project.h"

UT_TEST(ft_strdup)
{
	char	*c;

	c = "AbC";
	UT_ASSERT_EQ(strcmp(ft_strdup("aaaaa"), "aaaaa"), 0);
	UT_ASSERT_EQ(strcmp(ft_strdup(""), ""), 0);
	UT_ASSERT_NEQ(c, ft_strdup(c));
}

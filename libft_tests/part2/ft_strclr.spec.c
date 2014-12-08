#include "project.h"

UT_TEST(ft_strclr)
{
	char	str[] = "tttttt";

	ft_strclr(str);
	UT_ASSERT_EQ(memcmp(str, "\0\0\0\0\0\0", 7), 0);
}

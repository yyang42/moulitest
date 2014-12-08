#include "project.h"

UT_TEST(ft_strrchr)
{
	char	buf[] = "abcdedcba";

	UT_ASSERT_EQ(strrchr(buf, 'a'), ft_strrchr(buf, 'a'));
	UT_ASSERT_EQ(strrchr(buf, 0), ft_strrchr(buf, 0));
	UT_ASSERT_EQ(ft_strrchr(buf, 'z'), 0);
	buf[5] = 0;
	UT_ASSERT_EQ(ft_strrchr(buf, 'a'), buf);
}

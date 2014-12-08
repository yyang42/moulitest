#include "project.h"

UT_TEST(ft_strupcase)
{
	ft_strupcase(NULL);
	UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("")), ""), 0);
	UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("aaa")), "AAA"), 0);
	UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("zzz")), "ZZZ"), 0);
	UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("AAA")), "AAA"), 0);
	UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("ZZZ")), "ZZZ"), 0);
	UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("aBcDeé9123'47289")), "ABCDEé9123'47289"), 0);
}

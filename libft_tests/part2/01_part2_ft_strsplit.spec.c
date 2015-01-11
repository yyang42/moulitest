#include "project.h"

UT_TEST(ft_strsplit)
{
	char	**tt;

	tt = ft_strsplit("***salut****!**", '*');
	UT_ASSERT_EQ(strcmp(tt[0], "salut"), 0);
	UT_ASSERT_EQ(strcmp(tt[1], "!"), 0);
	UT_ASSERT_EQ(tt[2], NULL);

	tt = ft_strsplit("*****", '*');
	UT_ASSERT_EQ(tt[0], NULL);

	tt = ft_strsplit("coucou", '*');
	UT_ASSERT_EQ(strcmp(tt[0], "coucou"), 0);
	UT_ASSERT_EQ(tt[1], NULL);
	tt = ft_strsplit("salut****", '*');
	UT_ASSERT_EQ(strcmp(tt[0], "salut"), 0);
	UT_ASSERT_EQ(tt[1], NULL);

	tt = ft_strsplit("****salut", '*');
	UT_ASSERT_EQ(strcmp(tt[0], "salut"), 0);
	UT_ASSERT_EQ(tt[1], NULL);

	tt = ft_strsplit("", '*');
	UT_ASSERT(tt &&  tt[0] == NULL);

	/*ft_strsplit(NULL, 0);*/
}

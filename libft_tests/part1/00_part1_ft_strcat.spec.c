#include "project.h"

UT_TEST(ft_strcat)
{
	char	buf[9];

	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");
	UT_ASSERT_EQ(strcmp(buf, "Bonjour."), 0);
	UT_ASSERT_EQ(buf, ft_strcat(buf, ""));
}

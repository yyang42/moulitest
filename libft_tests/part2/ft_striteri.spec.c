#include "project.h"

UT_TEST(ft_striteri)
{
	char	str[] = "aBcDeF";

	ft_striteri(str, iti_test);
	UT_ASSERT_EQ(strcmp(str, "aCeGiK"), 0);
}

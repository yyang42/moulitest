#include "project.h"

UT_TEST(ft_tolower)
{
	UT_ASSERT_EQ(ft_tolower('T'), 't');
	UT_ASSERT_EQ(ft_tolower(99999), 99999);
	UT_ASSERT_EQ(ft_tolower('e'), 'e');
}

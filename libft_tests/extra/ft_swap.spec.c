#include "project.h"

UT_TEST(ft_swap)
{
	int test_swap1 = 24;
	int test_swap2 = 42;
	ft_swap(&test_swap1, &test_swap2);
	UT_ASSERT_EQ(test_swap1, 42);
	UT_ASSERT_EQ(test_swap2, 24);
}

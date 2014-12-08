#include "project.h"

UT_TEST(ft_memmove)
{
	char	testA1[] = "abcdef";
	char	testA2[] = "abcdef";

	ft_memmove(testA1 + 1, testA1, 5);
	ft_memmove(testA1 + 1, testA1, 0);
	memmove(testA2 + 1, testA2, 5);
	memmove(testA2 + 1, testA2, 0);
	UT_ASSERT(strcmp(testA1, "aabcde") == 0);
	UT_ASSERT(strcmp(testA1, testA2) == 0);

	char	testB1[] = "abcdef";
	char	testB2[] = "abcdef";

	ft_memmove(testB1, testB1 + 1, 5);
	ft_memmove(testB1, testB1 + 1, 0);
	memmove(testB2, testB2 + 1, 5);
	memmove(testB2, testB2 + 1, 0);
	UT_ASSERT(strcmp(testB1, "bcdeff") == 0);
	UT_ASSERT(strcmp(testB1, testB2) == 0);

	/* test edge cases */
	// char	test[] = "aaa";
	// UT_ASSERT_W(ft_memmove(NULL, test, 0) == memmove(NULL, test, 0));
	// UT_ASSERT_W(strcmp(memmove(test, NULL, 0), ft_memmove(test, NULL, 0)) == 0);
	// UT_ASSERT_W(ft_memmove(NULL, NULL, 0) == memmove(NULL, NULL, 0));
	// UT_ASSERT_W(ft_memmove(NULL, NULL, 100) == memmove(NULL, NULL, 100));
	// UT_ASSERT_W(ft_memmove(NULL, NULL, -100) == memmove(NULL, NULL, -100));

	/* The original memmove segfault or stops on those cases;
	
	memmove(NULL, test, 100);
	memmove(test, NULL, 100);
	memmove(NULL, test, -100);
	memmove(test, NULL, -100);
	*/
}

char	test1[] = "abcdef";
char	test2[] = "abcdef";

ft_memmove(test1 + 1, test1, 5);
ft_memmove(test1 + 1, test1, 0);
ft_memmove(test2 + 1, test2, 5);
ft_memmove(test2 + 1, test2, 0);
UT_ASSERT_EQ(strcmp(test1, "aabcde"), 0);
UT_ASSERT_EQ(strcmp(test1, test2), 0);

/* test edge cases */
char	test[] = "aaa";
UT_ASSERT(ft_memmove(NULL, test, 0) == memmove(NULL, test, 0));
UT_ASSERT(strcmp(memmove(test, NULL, 0), ft_memmove(test, NULL, 0)) == 0);
UT_ASSERT(ft_memmove(NULL, NULL, 0) == memmove(NULL, NULL, 0));
UT_ASSERT(ft_memmove(NULL, NULL, 100) == memmove(NULL, NULL, 100));
UT_ASSERT(ft_memmove(NULL, NULL, -100) == memmove(NULL, NULL, -100));

/* The original memmove segfault or stops on those cases;

	memmove(NULL, test, 100);
	memmove(test, NULL, 100);
	memmove(NULL, test, -100);
	memmove(test, NULL, -100);
*/

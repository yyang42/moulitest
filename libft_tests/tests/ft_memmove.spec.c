char	test[] = "abcdef";

ft_memmove(test + 1, test, 5);
ft_memmove(test + 1, test, 0);
UT_ASSERT_EQ(strcmp(test, "aabcde"), 0);

/* test edge cases */
UT_ASSERT(ft_memmove(NULL, test, 0) == NULL);
UT_ASSERT(ft_memmove(test, NULL, 0) == NULL);
UT_ASSERT(ft_memmove(NULL, NULL, 0) == NULL);
UT_ASSERT(ft_memmove(NULL, test, 100) == NULL);
UT_ASSERT(ft_memmove(test, NULL, 100) == NULL);
UT_ASSERT(ft_memmove(NULL, NULL, 100) == NULL);
UT_ASSERT(ft_memmove(NULL, test, -100) == NULL);
UT_ASSERT(ft_memmove(test, NULL, -100) == NULL);
UT_ASSERT(ft_memmove(NULL, NULL, -100) == NULL);

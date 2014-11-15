char	test[] = "abcdef";

ft_memmove(test + 1, test, 5);
ft_memmove(test + 1, test, 0);
UT_ASSERT_EQ(strcmp(test, "aabcde"), 0);

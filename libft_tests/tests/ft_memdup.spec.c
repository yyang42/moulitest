char	*c;

c = "AbC";
UT_ASSERT_EQ(strcmp(ft_memdup("aaaaa", 6), "aaaaa"), 0);
UT_ASSERT_EQ(strcmp(ft_memdup("", 1), ""), 0);
UT_ASSERT_NEQ(c, ft_memdup(c, 4));
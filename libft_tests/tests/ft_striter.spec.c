char	str[] = "aBcDeF";

ft_striter(str, it_test);
UT_ASSERT_EQ(strcmp(str, "bCdEfG"), 0);
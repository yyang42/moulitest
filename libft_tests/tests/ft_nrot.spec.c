UT_ASSERT_EQ(strcmp(ft_nrot(strdup("a"), 1), "b"), 0);
UT_ASSERT_EQ(strcmp(ft_nrot(strdup("A"), 5), "F"), 0);
UT_ASSERT_EQ(strcmp(ft_nrot(strdup("A"), 22), "W"), 0);
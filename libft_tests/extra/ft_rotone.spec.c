UT_ASSERT_EQ(strcmp(ft_rotone(strdup("a")), "b"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("A")), "B"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("z")), "a"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("Z")), "A"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("6")), "6"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("[")), "["), 0);
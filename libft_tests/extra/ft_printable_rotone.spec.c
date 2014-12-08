UT_ASSERT_EQ(strcmp(ft_printable_rotone(strdup("a")), "b"), 0);
UT_ASSERT_EQ(strcmp(ft_printable_rotone(strdup("z")), "{"), 0);
UT_ASSERT_EQ(strcmp(ft_printable_rotone(strdup("~")), " "), 0);
UT_ASSERT_EQ(strcmp(ft_printable_rotone(strdup("7")), "8"), 0);
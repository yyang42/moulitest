UT_ASSERT_EQ(strcmp(ft_strjoin("abc", "def"), "abcdef"), 0);
UT_ASSERT_EQ(strcmp(ft_strjoin("", ""), ""), 0);

ft_strjoin("", NULL);
ft_strjoin(NULL, "");
ft_strjoin(NULL, NULL);

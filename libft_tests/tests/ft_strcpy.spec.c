char	buf[6];

bzero(buf, 6);
ft_strcpy(buf, "abcde");
UT_ASSERT_EQ(strcmp(buf, "abcde"), 0);
ft_strcpy(buf, "abc");
UT_ASSERT_EQ(strcmp(buf, "abc"), 0);
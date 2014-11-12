char	buf[10];

bzero(buf, 10);
strcpy(buf, "abc");
ft_strlcat(buf, "abcdefghijklmnop", 10);
UT_ASSERT_EQ(strcmp(buf, "abcabcdef"), 0);
UT_ASSERT_EQ(ft_strlcat(buf, "abcd", 2), 6);
bzero(buf, 10);
UT_ASSERT_EQ(ft_strlcat(buf, "abc", 10), 3);
UT_ASSERT_EQ(ft_strlcat(buf, "def", 10), 6);
bzero(buf, 10);
memset(buf, 'a', 10);
UT_ASSERT_EQ(ft_strlcat(buf, "ccc", 10), 13);
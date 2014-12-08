char	buf1[] = "123456";
char	buf2[] = "12345";
char	buf3[] = "1";
char	buf4[] = "";

UT_ASSERT_EQ(strcmp(ft_strrev(buf1), "654321"), 0);
UT_ASSERT_EQ(strcmp(ft_strrev(buf2), "54321"), 0);
UT_ASSERT_EQ(strcmp(ft_strrev(buf3), "1"), 0);
UT_ASSERT_EQ(strcmp(ft_strrev(buf4), ""), 0);
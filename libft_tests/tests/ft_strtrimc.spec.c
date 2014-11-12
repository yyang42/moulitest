UT_ASSERT_EQ(strcmp(ft_strtrimc("*****AAA*****BBB*****", '*'), "AAA*****BBB"), 0);
UT_ASSERT_EQ(strcmp(ft_strtrimc("**********", '*'), ""), 0);
UT_ASSERT_EQ(strcmp(ft_strtrimc("", '*'), ""), 0);
UT_ASSERT_EQ(strcmp(ft_strtrimc("abc", '*'), "abc"), 0);
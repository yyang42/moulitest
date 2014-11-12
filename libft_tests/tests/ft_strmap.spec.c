char	*str;

str = "abcde";
str = ft_strmap(str, map_test);
UT_ASSERT_EQ(strcmp(str, "bcdef"), 0);

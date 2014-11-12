char	*str;

str = "abcde";
str = ft_strmapi(str, mapi_test);
UT_ASSERT_EQ(strcmp(str, "acegi"), 0);

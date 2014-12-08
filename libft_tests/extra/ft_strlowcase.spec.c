ft_strlowcase(NULL);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("")), ""), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("aaa")), "aaa"), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("zzz")), "zzz"), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("AAA")), "aaa"), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("ZZZ")), "zzz"), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("aBcDeé9123'47289")), "abcdeé9123'47289"), 0);
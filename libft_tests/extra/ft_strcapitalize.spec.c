ft_strcapitalize(NULL);
UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("bonjour les filles")), "Bonjour Les Filles"), 0);
UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("hello")), "Hello"), 0);
UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("hello2world")), "Hello2world"), 0);
UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("   je mange des pommes.  ")), "   Je Mange Des Pommes.  "), 0);
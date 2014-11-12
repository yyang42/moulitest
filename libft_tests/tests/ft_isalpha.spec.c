UT_ASSERT_NEQ(ft_isalpha('a'), 0);
UT_ASSERT_EQ(ft_isalpha('a' + 0x100), 0);
UT_ASSERT_EQ(ft_isalpha('2'), 0);
UT_ASSERT_NEQ(ft_isalpha('Z'), 0);
UT_ASSERT_NEQ(ft_isalpha('t'), 0);
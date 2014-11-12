UT_ASSERT_EQ(ft_isprint(0), 0);
UT_ASSERT_EQ(ft_isprint(127), 0);
UT_ASSERT_NEQ(ft_isprint(' '), 0);
UT_ASSERT_NEQ(ft_isprint('a'), 0);
UT_ASSERT_NEQ(ft_isprint(126), 0);
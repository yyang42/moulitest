UT_ASSERT_EQ(ft_isdigit(0), 0);
UT_ASSERT_NEQ(ft_isdigit('8'), 0);
UT_ASSERT_EQ(ft_isdigit('8' + 0x100), 0);
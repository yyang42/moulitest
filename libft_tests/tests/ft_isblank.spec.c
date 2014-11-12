UT_ASSERT_EQ(ft_isblank('\n'), isblank('\n'));
UT_ASSERT_EQ(ft_isblank(' '), isblank(' '));
UT_ASSERT_EQ(ft_isblank('\t'), isblank('\t'));
UT_ASSERT_EQ(ft_isblank('\v'), isblank('\v'));
UT_ASSERT_EQ(ft_isblank('8'), isblank('8'));
UT_ASSERT_EQ(ft_isblank('p'), isblank('p'));
UT_ASSERT_EQ(ft_isblank('/'), isblank('/'));
UT_ASSERT_EQ(ft_isblank('&'), isblank('&'));
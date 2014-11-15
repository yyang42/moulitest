char	b1[100], b2[100];

memset(b1, 33, 100);
memset(b2, 63, 100);
ft_memcpy(b1, b2, 100);
UT_ASSERT_EQ(memcmp(b1, b2, 100), 0);
UT_ASSERT_EQ(b1, ft_memcpy(b1, b2, 0));

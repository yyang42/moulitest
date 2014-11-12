char	b1[100], b2[100];

ft_memset(b1, 42, 100);
memset(b2, 42, 100);
UT_ASSERT_EQ(memset(b1, 99, 0), ft_memset(b1, 99, 0));
UT_ASSERT_EQ(memcmp(b1, b2, 100), 0);
b1[0] = 1;
ft_memset(b1, 0, 0);
UT_ASSERT_EQ(b1[0], 1);
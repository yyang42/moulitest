char	*t = "ab\0ab";


UT_ASSERT_EQ(ft_memcmp(t, t, 5), 0);
UT_ASSERT_NEQ(ft_memcmp(t, "abcab", 5) ,0);
UT_ASSERT(ft_memcmp("aaa", "aab", 4) < 0);
UT_ASSERT_EQ(ft_memcmp("aab", "aac", 2), 0);
UT_ASSERT_EQ(ft_memcmp("aww", "bpp", 0), 0);
UT_ASSERT(ft_memcmp("\200", "\0", 1) > 0);

/* test edge cases */
// UT_ASSERT_W(memcmp(NULL, NULL, 0) == ft_memcmp(NULL, NULL, 0));
// UT_ASSERT_W(memcmp(NULL, NULL, 10) == ft_memcmp(NULL, NULL, 10));

/* should not crash in those cases */
// memcmp(NULL, t, 10);
// ft_memcmp(NULL, t, 10);
// memcmp(t, NULL, 10);
// ft_memcmp(t, NULL, 10);

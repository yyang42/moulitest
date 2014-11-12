char	test[] = "abcdef";

UT_ASSERT_EQ(ft_memchr(test, 'a', 5), test);
UT_ASSERT_EQ(ft_memchr(test, 'c', 5), test + 2);
UT_ASSERT_EQ(ft_memchr(test, '\0', 7), memchr(test, '\0', 7));
UT_ASSERT_EQ(ft_memchr(test, 'z', 6), 0);
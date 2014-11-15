char	test[] = "abcdef";

UT_ASSERT(memchr(NULL, 0, 0) == ft_memchr(NULL, 0, 0));

memchr(NULL, 0, 10);
ft_memchr(NULL, 0, 10);

memchr(NULL, -10, 10);
ft_memchr(NULL, -10, 10);

UT_ASSERT_EQ(ft_memchr(test, 'a', 5), test);
UT_ASSERT_EQ(ft_memchr(test, 'c', 5), test + 2);
UT_ASSERT_EQ(ft_memchr(test, '\0', 7), memchr(test, '\0', 7));
UT_ASSERT_EQ(ft_memchr(test, 'z', 6), 0);

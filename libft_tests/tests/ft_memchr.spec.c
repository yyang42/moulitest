UT_ASSERT(memchr(NULL, 0, 0) == ft_memchr(NULL, 0, 0));

memchr(NULL, 0, 10);
ft_memchr(NULL, 0, 10);

memchr(NULL, -10, 10);
ft_memchr(NULL, -10, 10);

UT_ASSERT_EQ(ft_memchr("abcdef", 'a', 5), memchr("abcdef", 'a', 5));
UT_ASSERT_EQ(ft_memchr("abcdef", 'c', 5), memchr("abcdef", 'c', 5));
UT_ASSERT_EQ(ft_memchr("abcdef", '\0', 7), memchr("abcdef", '\0', 7));
UT_ASSERT_EQ(ft_memchr("abcdef", 'z', 6), memchr("abcdef", 'z', 6));
UT_ASSERT_EQ(ft_memchr("abcdef", 999, 6), memchr("abcdef", 999, 6));
UT_ASSERT_EQ(ft_memchr("abcdef", 9999999, 6), memchr("abcdef", 9999999, 6));
UT_ASSERT_EQ(ft_memchr("abcdef", -55, 9999), memchr("abcdef", -55, 9999));

UT_ASSERT_EQ(ft_memchr("slfkjlsdajfladjslfjldsj", -55, 9999), memchr("slfkjlsdajfladjslfjldsj", -55, 9999));
UT_ASSERT_EQ(ft_memchr("slfkjlsdajfladjslfjldsjslfkjlsdajfladjslfjldsjslfkjlsdajfladjslfjldsjslfkjlsdajfladj", -55, 9999),
				memchr("slfkjlsdajfladjslfjldsjslfkjlsdajfladjslfjldsjslfkjlsdajfladjslfjldsjslfkjlsdajfladj", -55, 9999));

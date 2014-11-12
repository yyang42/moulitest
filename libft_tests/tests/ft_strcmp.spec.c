	/* No need to test for NULL value
	**
	** ft_strcmp(NULL, NULL)
	**
	** The standard strcmp function return this error:
	** error: null argument where non-null required
	*/
	UT_ASSERT_EQ(ft_strcmp("abc", "abc"), 0);
	UT_ASSERT(ft_strcmp("abc", "abd") < 0);
	UT_ASSERT(ft_strcmp("\200", "\0") > 0);
	UT_ASSERT_NEQ(ft_strcmp("a", "abcde"), 0);
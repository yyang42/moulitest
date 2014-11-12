void	*mem;

mem = malloc(2000);
ft_memdel(&mem);
UT_ASSERT_EQ(mem, NULL);
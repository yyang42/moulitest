 /* Two contributor for this test */
char	was_a = 'a';
char	was_b = 'b';
int		was_1 = 1;
int		was_2 = 2;
char	was_toto[] = "toto";
char	was_tata[] = "tata";

char test_swap_str_1[] = "coucou les filles";
char test_swap_str_2[] = "bonjour jambon po";
int test_swap_int_1 = 24;
int test_swap_int_2 = 42;

ft_memswap(&was_a, &was_b, sizeof(char));
UT_ASSERT(was_a == 'b');
UT_ASSERT(was_b == 'a');
ft_memswap(&was_1, &was_2, sizeof(int));
UT_ASSERT(was_1 == 2);
UT_ASSERT(was_2 == 1);
ft_memswap(&was_1, &was_2, 0);
UT_ASSERT(was_1 == 2);
UT_ASSERT(was_2 == 1);
ft_memswap(was_toto, was_tata, sizeof(char) * 2);
UT_ASSERT_EQ(strcmp(was_toto, "tato"), 0);
UT_ASSERT_EQ(strcmp(was_tata, "tota"), 0);

ft_memswap(&test_swap_str_1, &test_swap_str_2, ft_strlen(test_swap_str_2));
ft_memswap(&test_swap_int_1, &test_swap_int_2, 2);
UT_ASSERT_EQ(strcmp(test_swap_str_1, "bonjour jambon po"), 0);
UT_ASSERT_EQ(strcmp(test_swap_str_2, "coucou les filles"), 0);
UT_ASSERT_EQ(test_swap_int_1, 42);
UT_ASSERT_EQ(test_swap_int_2, 24);

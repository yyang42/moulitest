int		was_1 = 1;
int		was_2 = 2;
char	was_a = 'a';
char	was_b = 'b';
int		*ptr_1 = &was_1;
int		*ptr_2 = &was_2;
char	*ptr_a = &was_a;
char	*ptr_b = &was_b;

ft_ptrswap(&ptr_1, &ptr_2);
ft_ptrswap(&ptr_a, &ptr_b);
UT_ASSERT(*ptr_1 == 2);
UT_ASSERT(*ptr_2 == 1);
UT_ASSERT(*ptr_a == 'b');
UT_ASSERT(*ptr_b == 'a');
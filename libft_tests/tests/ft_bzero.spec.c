char	b1[10], b2[10];

bzero(NULL, 0);
ft_bzero(NULL, 0);

bzero(b1, 10);
ft_bzero(b2, 10);
UT_ASSERT_EQ(memcmp(b1, b2, 10), 0);
b1[0] = 1;
ft_bzero(b1, 0);
UT_ASSERT_EQ(b1[0], 1);


// UT_ASSERT(1 == 1);
// UT_ASSERT(0 == 1);
int a = 1;
int b = 2;
UT_ASSERT((a == b) || (a == b));
// UT_ASSERT_OP(0 == 1);
// UT_ASSERT(1 == 1);
// UT_ASSERT(1 == 0);

char	b1[100], b2[100];

memset(b1, 33, 100);
memset(b2, 63, 100);

ft_memcpy(b1, b2, 100);
UT_ASSERT(memcmp(b1, b2, 100) == 0);
UT_ASSERT(ft_memcpy(b1, b2, 0) == b1);

/* test edge cases */
memcpy(NULL, NULL, 0); /* The original memcpy does not segfault. */
UT_ASSERT(ft_memcpy(NULL, NULL, 0) == memcpy(NULL, NULL, 0));

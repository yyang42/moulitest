int test_ft_sort[7] = {42,4,98,9,12,68,21};

ft_sort_int_table(test_ft_sort, 7);
UT_ASSERT_EQ(test_ft_sort[0], 4);
UT_ASSERT_EQ(test_ft_sort[1], 9);
UT_ASSERT_EQ(test_ft_sort[2], 12);
UT_ASSERT_EQ(test_ft_sort[3], 21);
UT_ASSERT_EQ(test_ft_sort[4], 42);
UT_ASSERT_EQ(test_ft_sort[5], 68);
UT_ASSERT_EQ(test_ft_sort[6], 98);
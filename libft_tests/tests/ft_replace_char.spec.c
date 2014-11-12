char test_change[] = "Coucou les filles";
char *return_test_change;

return_test_change = (char *)malloc(strlen(test_change) + 1);

return_test_change = ft_replace_char(test_change, 'o', 'r');
UT_ASSERT_EQ(strcmp(return_test_change, "Crucru les filles"), 0);
reset_sandbox();
sandbox_cmd("touch a b c AA BB CC");

// printf("\n===================\n");
// printf("%s", ls("-1"));
// printf("\n===================\n");
// printf("%s", ft_ls("."));
// printf("\n===================\n");

UT_ASSERT(strcmp(ft_ls("."), "AA\nBB\nCC\na\nb\nc\n") == 0);
UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p a b c AA BB CC");
UT_ASSERT(strcmp(ls("-R"), ft_ls("-R")) == 0);

// UT_ASSERT(strcmp(ft_ls("-R"), "aaa\nbbb\nccc\n") == 0);
// printf("{%s}\n", ls("-1"));
// printf("\n===================\n");
// printf("%s", ls("-R"));
// printf("\n===================\n");
// printf("%s", ft_ls("-R"));
// printf("\n===================\n");

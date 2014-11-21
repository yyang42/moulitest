reset_sandbox();
sandbox_cmd("mkdir -p level1_{1..2}/level2_{1..2}/level3_{1..2}");
UT_ASSERT(strcmp(ls("-R"), ft_ls("-R")) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p level1_{1..5}/level2_{6..10}/level3_{11..15}");
UT_ASSERT(strcmp(ls("-R"), ft_ls("-R")) == 0);


// UT_ASSERT(strcmp(ft_ls("-R"), "aaa\nbbb\nccc\n") == 0);
// printf("{%s}\n", ls("-1"));
// printf("\n===================\n");
// printf("%s", ls("-R"));
// printf("\n===================\n");
// printf("%s", ft_ls("-R"));
// printf("\n===================\n");

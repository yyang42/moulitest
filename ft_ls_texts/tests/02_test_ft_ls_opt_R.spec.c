reset_sandbox();
sandbox_cmd("mkdir -p level1_{1..2}/level2_{1..2}/level3_{1..2}");
UT_ASSERT(strcmp(ls("-1R"), ft_ls("-1R")) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p level1_{1..5}/level2_{6..10}/level3_{11..15}");
UT_ASSERT(strcmp(ls("-1R"), ft_ls("-1R")) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p .a .b .c && mkdir -p a b c ");
// printf("\n===================\n");
// printf("%s", ls("-1R"));
// printf("\n===================\n");
// printf("%s", ft_ls("-1R"));
// printf("\n===================\n");

UT_ASSERT(strcmp(ls("-1R"), ft_ls("-1R")) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p level1_{1..2}/level2_{1..2}/level3_{1..2}");
// UT_ASSERT(strcmp(ft_ls("-R"), "aaa\nbbb\nccc\n") == 0);
// printf("{%s}\n", ls("-1"));
printf("\n===================\n");
printf("%s", ls("-R"));
printf("\n===================\n");
printf("%s", ft_ls("-R"));
printf("\n===================\n");
UT_ASSERT(strcmp(ls("-R"), ft_ls("-R")) == 0);

// reset_sandbox();
// UT_ASSERT(strcmp(ft_ls("."), "") == 0);
// UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

// reset_sandbox();
// sandbox_cmd("touch file{001..1000}");
// UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

// reset_sandbox();

// printf("\n=====  ls  ========\n");
// printf("%s", ls("-1 | cat -e"));
// printf("===== ft ls =======\n");
// printf("%s", ft_ls(". | cat -e"));
// printf("==================\n");

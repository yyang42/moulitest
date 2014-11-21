reset_sandbox();
sandbox_cmd("touch aaa bbb ccc");
UT_ASSERT(strcmp(ft_ls("."), "aaa\nbbb\nccc\n") == 0);
UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

reset_sandbox();
UT_ASSERT(strcmp(ft_ls("."), "") == 0);
UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

reset_sandbox();
sandbox_cmd("touch file{001..1000}");
UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

reset_sandbox();
sandbox_cmd("touch aaa bbb");
UT_ASSERT(strcmp(ls("-1"), ft_ls("")) == 0);

reset_sandbox();

// printf("\n=====  ls  ========\n");
// printf("%s", ls("-1 | cat -e"));
// printf("===== ft ls =======\n");
// printf("%s", ft_ls(". | cat -e"));
// printf("==================\n");

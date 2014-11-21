reset_sandbox();
sandbox_cmd("touch aaa bbb ccc");
UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

reset_sandbox();
UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

// printf("\n=====  ls  ========\n");
// printf("%s", ls("-1 | cat -e"));
// printf("===== ft ls =======\n");
// printf("%s", ft_ls(". | cat -e"));
// printf("==================\n");

// ft_ls(".");

// reset_sandbox(); sandbox_cmd("touch aaa");

// reset_sandbox();
// ls("-1");
// // sandbox_cmd("touch aaa bbb ccc");
// ft_ls(".");
// UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);
// reset_sandbox(); sandbox_cmd("touch aaa bbb");
// UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

// reset_sandbox(); sandbox_cmd("touch aaa ccc");
// UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

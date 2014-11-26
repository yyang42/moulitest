char *cmd;

cmd = "-1";
reset_sandbox();
sandbox_cmd("touch aaa bbb ccc");
UT_ASSERT(strcmp(ft_ls(cmd), "aaa\nbbb\nccc\n") == 0);
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
UT_ASSERT(strcmp(ft_ls(cmd), "") == 0);
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file{01..10}");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch aaa bbb");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch aaa");
UT_ASSERT(strcmp(ls("-1 aaa"), ft_ls("-1 aaa")) == 0);

// printf("\n=====  ls  ========\n");
// printf("%s", ls("-1 | cat -e"));
// printf("===== ft ls =======\n");
// printf("%s", ft_ls(". | cat -e"));
// printf("==================\n");

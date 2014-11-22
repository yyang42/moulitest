char *cmd = "-1rR";

reset_sandbox();
sandbox_cmd("mkdir -p level1_{1..2}/level2_{1..2}/level3_{1..2}");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p level1_{1..5}/level2_{6..10}/level3_{11..15}");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p .a .b .c && mkdir -p a b c ");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

// printf("\n===================\n");
// printf("%s", ls(cmd));
// printf("\n===================\n");
// printf("%s", ft_ls(cmd));
// printf("\n===================\n");

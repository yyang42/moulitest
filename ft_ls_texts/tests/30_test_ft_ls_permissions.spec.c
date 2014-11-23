char *cmd = "-1l";

reset_sandbox();
sandbox_cmd("touch file && chmod 0777 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 1777 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 2777 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 3777 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 4777 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 5777 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 6777 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 7777 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 0000 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 1000 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 2000 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 3000 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 4000 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 5000 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 6000 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch file && chmod 7000 file");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

/*
printf("\n=====  ls  ========\n");
printf("%s", ls(cmd));
printf("===== ft ls =======\n");
printf("%s", ft_ls(cmd));
printf("==================\n");

*/
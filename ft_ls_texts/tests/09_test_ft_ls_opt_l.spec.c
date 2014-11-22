char *cmd = "-l";


reset_sandbox();
sandbox_cmd("touch a b c");


printf("\n=====  ls  ========\n");
printf("%s", ls(cmd));
printf("===== ft ls =======\n");
printf("%s", ft_ls(cmd));
printf("==================\n");


UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

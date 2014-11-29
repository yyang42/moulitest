char *cmd = "-1A";

reset_sandbox();
sandbox_cmd("mkdir .a a");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("mkdir .hiddendir{1..10} dir{1..10} && touch .hiddenfile{1..10} file{1..10}");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

/*
printf("\n=====  ls  ========\n");
printf("%s", ls("-1A"));
printf("===== ft ls =======\n");
printf("%s", ft_ls("-A"));
printf("==================\n");
*/

reset_sandbox();
char *cmd;

cmd = "-alR /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

/*
printf("\n========== ls ==========\n");
printf(ls(cmd));
printf("========= ft_ls ========\n");
printf(ft_ls(cmd));
printf("========================\n");
*/

cmd = "-tla /usr";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

/*
printf("\n========== ls ==========\n");
printf(ls(cmd));
printf("========= ft_ls ========\n");
printf(ft_ls(cmd));
printf("========================\n");
*/

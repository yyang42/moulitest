reset_sandbox();
char *cmd;

cmd = "-lR /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-alR /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-l /usr";
UT_ASSERT(strcmp(ls("-l /usr > ls_out"), ft_ls("-l /usr > ft_ls_out")) == 0);


cmd = "-t /usr";
printf("\n=====  ls  ========\n");
printf("%s", ls(cmd));
printf("===== ft ls =======\n");
printf("%s", ft_ls(cmd));
printf("==================\n");
UT_ASSERT(strcmp(ls("-t /usr"), ft_ls("-t /usr")) == 0);
// UT_ASSERT(strcmp(ls("-alt /usr/bin > ls_out"), ft_ls("-alt /usr/bin > ft_ls_out")) == 0);


// cmd = "-alRt /usr/bin";
// UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

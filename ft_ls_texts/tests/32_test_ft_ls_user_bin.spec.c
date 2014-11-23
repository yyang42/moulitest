reset_sandbox();
char *cmd;

cmd = "-lR /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-alR /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-alRt /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);


cmd = "-alRt /usr/bin";
// printf("\n=====  ls  ========\n");
// printf("%s", ls(cmd));
// printf("===== ft ls =======\n");
// printf("%s", ft_ls(cmd));
// printf("==================\n");
UT_ASSERT(strcmp(ls("-alRt /usr/bin > ls_out"), ft_ls("-alRt /usr/bin > ft_ls_out")) == 0);

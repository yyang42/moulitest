reset_sandbox();
char *cmd;

cmd = "-lR /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-alR /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-l /usr";
UT_ASSERT(strcmp(ls("-l /usr > ls_out"), ft_ls("-l /usr > ft_ls_out")) == 0);

cmd = "-tl /usr";
UT_ASSERT(strcmp(ls("-t /usr"), ft_ls("-t /usr")) == 0);

cmd = "-tl /usr";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-tla /usr";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
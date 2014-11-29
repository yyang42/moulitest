reset_sandbox();
char *cmd;

cmd = "-lR /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-l /usr";
UT_ASSERT(strcmp(ls("-l /usr"), ft_ls("-l /usr")) == 0);

cmd = "-tl /usr";
UT_ASSERT(strcmp(ls("-t /usr"), ft_ls("-t /usr")) == 0);

cmd = "-tl /usr";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

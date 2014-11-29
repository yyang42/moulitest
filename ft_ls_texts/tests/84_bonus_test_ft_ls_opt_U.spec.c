reset_sandbox();
char *cmd;

cmd = "-lU /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-lUr /usr/bin";
UT_ASSERT(strcmp(ls("-l /usr"), ft_ls("-l /usr")) == 0);

cmd = "-tu1 /usr/bin";
UT_ASSERT(strcmp(ls("-t /usr"), ft_ls("-t /usr")) == 0);

cmd = "-turl /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

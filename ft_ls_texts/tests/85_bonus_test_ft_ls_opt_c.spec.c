reset_sandbox();
char *cmd;

cmd = "-lU /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-lUr /usr/share";
UT_ASSERT(strcmp(ls("-l /usr"), ft_ls("-l /usr")) == 0);

cmd = "-tu1 /usr/share";
UT_ASSERT(strcmp(ls("-t /usr"), ft_ls("-t /usr")) == 0);

cmd = "-turl /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

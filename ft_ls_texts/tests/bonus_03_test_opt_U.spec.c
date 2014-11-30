char *cmd;

cmd = "-lU /usr";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-1tU /usr";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-1tlU /usr";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

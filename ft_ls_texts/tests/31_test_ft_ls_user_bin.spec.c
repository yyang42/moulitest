char *cmd = "-lR /usr/bin";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

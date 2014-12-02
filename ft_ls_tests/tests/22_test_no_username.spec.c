char *cmd;

reset_sandbox();
cmd = "-l /usr/local/bin/node";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

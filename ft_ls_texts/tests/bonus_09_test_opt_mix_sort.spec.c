char *cmd;

cmd = "-ARSUacdlprtu /usr/share";

UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-utrpldcaUSRA /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

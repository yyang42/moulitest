reset_sandbox();
char *cmd;

cmd = "-tc /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-tcr /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-ltc /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-lcr /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-lUr /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-tu1 /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

cmd = "-turl /usr/share";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

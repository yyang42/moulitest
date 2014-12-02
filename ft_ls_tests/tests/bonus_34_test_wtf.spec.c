char *cmd = "-l";

cmd = "-1R /usr/share/norminette/rbx/2.1/gems/redis-3.1.0";
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

UT_ASSERT_W("Pas encore de test pour /" == 0);


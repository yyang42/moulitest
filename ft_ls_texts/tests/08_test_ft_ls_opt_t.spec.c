char *cmd = "-1t";

reset_sandbox();
sandbox_cmd("touch a b c d e && touch 20420101 c");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch 20140103 a && touch 20140101 b && touch 2014012 c");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

// reset_sandbox();
// sandbox_cmd("mkdir -p a b c AA BB CC");
// UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

// reset_sandbox();
// sandbox_cmd("mkdir -p POP mok POPO liu && touch PIP mik PIPI lui");
// UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);


printf("\n=====  ls  ========\n");
printf("%s", ls(cmd));
printf("===== ft ls =======\n");
printf("%s", ft_ls(cmd));
printf("==================\n");


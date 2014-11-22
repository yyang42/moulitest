char *cmd = "-1t";

reset_sandbox();
sandbox_cmd("touch a b c d e && touch 20420101 c");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch 02010103 a && touch 01010101 b && touch 03010102 c");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch fileA{1..20} fileB{1..20} fileC{1..20} && touch 02010101 fileA{1..20} && touch 01010707 fileB{1..20} && touch 03011212 fileC{1..20}");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

/*
printf("\n=====  ls  ========\n");
printf("%s", ls(cmd));
printf("===== ft ls =======\n");
printf("%s", ft_ls(cmd));
printf("==================\n");

*/
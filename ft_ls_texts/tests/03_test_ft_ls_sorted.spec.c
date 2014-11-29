char *cmd = "-1";

reset_sandbox();
sandbox_cmd("touch a b c AA BB CC");
UT_ASSERT(strcmp(ft_ls(cmd), "AA\nBB\nCC\na\nb\nc\n") == 0);
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p a b c AA BB CC");
UT_ASSERT(strcmp(ft_ls(cmd), "AA\nBB\nCC\na\nb\nc\n") == 0);
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p POP mok POPO liu && touch PIP mik PIPI lui");
UT_ASSERT(strcmp(ft_ls(cmd), "PIP\nPIPI\nPOP\nPOPO\nliu\nlui\nmik\nmok\n") == 0);
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

// printf("\n===================\n");
// printf("%s", ls("-1R"));
// printf("\n===================\n");
// printf("%s", ft_ls("-R"));
// printf("\n===================\n");

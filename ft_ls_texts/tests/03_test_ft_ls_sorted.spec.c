reset_sandbox();
sandbox_cmd("touch a b c AA BB CC");
UT_ASSERT(strcmp(ft_ls("."), "AA\nBB\nCC\na\nb\nc\n") == 0);
UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p a b c AA BB CC");
UT_ASSERT(strcmp(ft_ls("."), "AA\nBB\nCC\na\nb\nc\n") == 0);
UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p POP mok POPO liu && touch PIP mik PIPI lui");
UT_ASSERT(strcmp(ft_ls("."), "PIP\nPIPI\nPOP\nPOPO\nliu\nlui\nmik\nmok\n") == 0);
UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

reset_sandbox();
sandbox_cmd("mkdir -p aa bb cc A B C && cd aa && mkdir aa bb cc A B C");
UT_ASSERT(strcmp(ls("-1R"), ft_ls("-R")) == 0);

// printf("\n===================\n");
// printf("%s", ls("-1R"));
// printf("\n===================\n");
// printf("%s", ft_ls("-R"));
// printf("\n===================\n");

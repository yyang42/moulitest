char *cmd = "-l";

reset_sandbox();
sandbox_cmd("touch a b c");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch a b c && echo 'coucou' > a &&  echo 'hello world' > b");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch a b c && echo 'coucou' > a &&  echo 'hello world' > b");
sandbox_cmd("mkdir 111 222 333 444 && touch 111/{a,b,c} && echo 'eat pizza' > 111/a");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

reset_sandbox();
sandbox_cmd("touch a b c && ln a a_ln && ln -s b b_lns && mkdir bonjour");
sandbox_cmd("ln a abcdefghtmlfjsldjfoiaufjlksdjflaslf4654656545lfjsdlfjasi");

UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

/*
printf("\n=====  ls  ========\n");
printf("%s", ls(cmd));
printf("===== ft ls =======\n");
printf("%s", ft_ls(cmd));
printf("==================\n");
*/
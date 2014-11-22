reset_sandbox();
sandbox_cmd("mkdir .a a");
UT_ASSERT(strcmp(ls("-1a"), ft_ls("-a")) == 0);


printf("\n=====  ls  ========\n");
printf("%s", ls("-1a | cat -e"));
printf("===== ft ls =======\n");
printf("%s", ft_ls("-a | cat -e"));
printf("==================\n");

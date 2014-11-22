reset_sandbox();
sandbox_cmd("mkdir mydir mydir2 && touch mydir/{aaa,bbb,ccc} && touch mydir2/{111,222,333}");
printf("\n=====  ls  ========\n");
printf("%s", ls("-1 mydir mydir2 | cat -e"));
printf("===== ft ls =======\n");
printf("%s", ft_ls("mydir mydir2 | cat -e"));
printf("==================\n");

// UT_ASSERT(strcmp(ls("-1"), ft_ls(".")) == 0);

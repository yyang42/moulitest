reset_sandbox();
sandbox_cmd("mkdir mydir && ln -s mydir symdir && touch mydir/file{1..5}");

UT_ASSERT(strcmp(ls("-l symdir"), ft_ls("-l symdir")) == 0);

UT_ASSERT(strcmp(ls("-1 symdir"), ft_ls("-1 symdir")) == 0);

/*
printf("\n===================\n");
printf("%s", ls("-1 symdir"));
printf("\n===================\n");
printf("%s", ft_ls("-1 symdir"));
printf("\n===================\n");
*/

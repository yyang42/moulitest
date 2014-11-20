printf("\n==================\n");
printf("%s", ls(""));
printf("=====  ls  ========\n");
printf("%s", ft_ls("-1"));
printf("===== ft ls =======\n");
UT_ASSERT(ls("") == ft_ls(""));

reset_sandbox();
char *cmd;
char *ls_out = (char *)malloc(1000000);
char *ft_ls_out = (char *)malloc(1000000);

UT_ASSERT(strcmp(ls("-1 /dev"), ft_ls("-1 /dev")) == 0);
UT_ASSERT(strcmp(ls("-1l /dev | grep -v io8"), ft_ls("-1l /dev | grep -v io8")) == 0);
UT_ASSERT(strcmp(ls("-1la /dev | grep -v io8"), ft_ls("-1la /dev | grep -v io8")) == 0);

/*
printf("\n===================\n");
printf("%s", ls("-1l /dev | grep -v io8"));
printf("\n===================\n");
printf("%s", ft_ls("-1l /dev | grep -v io8"));
printf("\n===================\n");
*/

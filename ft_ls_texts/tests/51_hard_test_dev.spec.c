reset_sandbox();
char *cmd;
char *ls_out = (char *)malloc(1000000);
char *ft_ls_out = (char *)malloc(1000000);

UT_ASSERT(strcmp(ls("-1 /dev"), ft_ls("-1 /dev")) == 0);

/* io8 ignored because its minor device is not stable */
UT_ASSERT(strcmp(ls("-1l /dev | grep -v io8"), ft_ls("-1l /dev | grep -v io8")) == 0);
UT_ASSERT(strcmp(ls("-1la /dev | grep -v io8"), ft_ls("-1la /dev | grep -v io8")) == 0);

/*
printf("\n===================\n");
printf("%s", ls("-1R /dev"));
printf("\n===================\n");
printf("%s", ft_ls("-1R /dev"));
printf("\n===================\n");
*/

/* next challenge
// ls("-1R /dev");
// ft_ls("-1R /dev");
// UT_ASSERT(strcmp(ls("-1R /dev | tee > ls.out"), ft_ls("-1R /dev | tee > ft_ls.out")) == 0);
 */

char *cmd;
reset_sandbox();

cmd = "does_not_exit";
UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);

sandbox_cmd("mkdir -p not_allowed_file");
sandbox_cmd("chmod 000 not_allowed_file");
cmd = "not_allowed_file";
UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);
reset_sandbox();

cmd = "-Z_this_option_does_not_exist";
// printf("\n===================\n");
// printf("%s", ls_err(cmd));
// printf("\n===================\n");
// printf("%s", ft_ls_err(cmd));
// printf("\n===================\n");
UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);

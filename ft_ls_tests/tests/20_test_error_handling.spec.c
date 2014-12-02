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
UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);

cmd = "-la--t"; // Invalid hyphen option
UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);


cmd = "\"\"";
UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);

cmd = "''";
UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);

sandbox_cmd("touch a b");

cmd = "a '' b";
UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);

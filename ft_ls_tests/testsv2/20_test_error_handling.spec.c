#include <project.h>

static char *strip_illegal_opt_err(char *str)
{
	str = re_replace(str, "^.*ls: ", "XXXXls: ");
	str = re_replace(str, "usage: (ft_)?ls", "usage: XXXX");
	str = re_replace(str, "\\[-[^]]+\\] ", "[XXXX] ");
	return (str);
}

static char *strip_no_such_file_or_dir(char *str)
{
	str = re_replace(str, "[^\n]*ls: ", "XXXXls: ");
	return (str);
}

UT_TEST(20_test_error_handling)
{
	char *cmd;
	reset_sandbox();
	char *ls_out_str;
	char *ft_ls_out_str;

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

	cmd = "--a";
	UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);

	cmd = "\"\"";
	UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);

	cmd = "''";
	UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);

	sandbox_cmd("touch a b");

	cmd = "a '' b";
	UT_ASSERT(strlen(ft_ls_err(cmd)) > 0);


	cmd = "-AZWYX243";
	ft_ls_out_str = strip_illegal_opt_err(ft_ls(cmd));
	ls_out_str = strip_illegal_opt_err(ls(cmd));
	UT_ASSERT_W(strequ(ls_out_str, ft_ls_out_str));

	cmd = "--a";
	ft_ls_out_str = strip_illegal_opt_err(ft_ls(cmd));
	ls_out_str = strip_illegal_opt_err(ls(cmd));
	UT_ASSERT_W(strequ(ls_out_str, ft_ls_out_str));

	reset_sandbox();

	cmd = "a b";
	ft_ls_out_str = strip_no_such_file_or_dir(ft_ls(cmd));
	ls_out_str = strip_no_such_file_or_dir(ls(cmd));
	UT_ASSERT_W(strequ(ls_out_str, ft_ls_out_str));

/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls_err(cmd));
	printf("===== ft ls =======\n");
	printf("%s", ft_ls_err(cmd));
	printf("==================\n");
*/

/*
	printf("\n=====  ls  ========\n");
	printf("%s", ls_out_str);
	printf("===== ft ls =======\n");
	printf("%s", ft_ls_out_str);
	printf("==================\n");
*/
}
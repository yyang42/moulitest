#include <project.h>



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


	cmd = "-lZWYX243";
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


	reset_sandbox();
	sandbox_cmd("mkdir b");
	cmd = "-1 a b";
	ft_ls_out_str = strip_no_such_file_or_dir(ft_ls(cmd));
	ls_out_str = strip_no_such_file_or_dir(ls(cmd));
	UT_ASSERT_W(strequ(ls_out_str, ft_ls_out_str));

	reset_sandbox();
	sandbox_cmd("mkdir adir zdir");
	sandbox_cmd("touch afile zfile");
	sandbox_cmd("ln -s adir asymdir");
	sandbox_cmd("ln -s adir zsymdir");
	sandbox_cmd("ln -s afile asymfile");
	sandbox_cmd("ln -s afile zsymfile");
	cmd = "-1 adir zdir aNotExist zNotExistB afile zfile asymdir zsymdir asymfile zsymfile";
	ft_ls_out_str = strip_no_such_file_or_dir(ft_ls(cmd));
	ls_out_str = strip_no_such_file_or_dir(ls(cmd));
	UT_ASSERT_W(strequ(ls_out_str, ft_ls_out_str));

	reset_sandbox();
	sandbox_cmd("touch K j l");
	cmd = "-1r a c b l K j";
	ft_ls_out_str = strip_no_such_file_or_dir(ft_ls(cmd));
	ls_out_str = strip_no_such_file_or_dir(ls(cmd));
	// printf("\n=====  ls  ========\n");
	// printf("%s", ls_out_str);
	// printf("===== ft ls =======\n");
	// printf("%s", ft_ls_out_str);
	// printf("==================\n");
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

reset_sandbox();
// sandbox_cmd("touch file && xattr -w theAnswerIs42 whatever_you_want file");

// printf("\n===================\n");
// printf("%s", ls("-1l /dev/fd"));
// printf("\n===================\n");
// printf("%s", ft_ls("-1l /dev/fd"));
// printf("\n===================\n");

/* This test never match because the ls and ft_ls are launched differently
	May as different user (tty vs current_group)

	UT_ASSERT(strcmp(ls("-1l /dev/fd"), ft_ls("-1l /dev/fd")) == 0);
*/
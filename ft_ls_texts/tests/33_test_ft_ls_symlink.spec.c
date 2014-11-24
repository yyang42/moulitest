reset_sandbox();
sandbox_cmd("mkdir mydir && ln -s mydir symdir && touch mydir/file{1..5}");
UT_ASSERT(strcmp(ls("-1l symdir"), ft_ls("-1l symdir")) == 0);

// printf("\n===================\n");
// printf("%s", ls("-1l symdir"));
// printf("\n===================\n");
// printf("%s", ft_ls("-1l symdir"));
// printf("\n===================\n");


// sandbox_cmd("mkdir mydir mydir/subdir && ln -s mydir/subdir symdir && touch mydir/subdir/file{1..5}");

// printf("\n===================\n");
// printf("%s", ls("-1l symdir"));
// printf("\n===================\n");
// printf("%s", ft_ls("-1l symdir"));
// printf("\n===================\n");

/* This test never match because the ls and ft_ls are launched differently
	May as different user (tty vs current_group)

	UT_ASSERT(strcmp(ls("-1l /dev/fd"), ft_ls("-1l /dev/fd")) == 0);
*/
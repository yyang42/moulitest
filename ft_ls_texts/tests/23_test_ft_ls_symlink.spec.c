reset_sandbox();
sandbox_cmd("mkdir mydir && ln -s mydir symdir && touch mydir/file{1..5}");
UT_ASSERT(strcmp(ls("-1l symdir"), ft_ls("-1l symdir")) == 0);

/* This test never match because the ls and ft_ls are launched differently
	Both commands may be launched as different user (tty vs current_group)

	UT_ASSERT(strcmp(ls("-1l /dev/fd"), ft_ls("-1l /dev/fd")) == 0);
*/

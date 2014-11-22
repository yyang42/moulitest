char *cmd = "-la";

reset_sandbox();
sandbox_cmd("mkdir dir{1..5} .hdir{1..5}");
sandbox_cmd("touch dir1/file{1..5} dir1/.hfile{1..5}");
sandbox_cmd("touch .hdir1/file{1..5} .hdir1/.hfile{1..5}");
sandbox_cmd("touch .hdir1/file{1..5} .hdir1/.hfile{1..5}");
sandbox_cmd("touch a && ln -s a symlink");



/*

cmd = "-1aR";
reset_sandbox();
sandbox_cmd("mkdir .dir1A .dir1B && mkdir .dir1A/dir2{A,B} && touch .dir1A/dir2A/file3A");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

*/





// printf("\n=====  ls  ========\n");
// printf("%s", ls(cmd));
// printf("===== ft ls =======\n");
// printf("%s", ft_ls(cmd));
// printf("==================\n");

// reset_sandbox();
// cmd = "-1R ~/Downloads";
// printf("\n=====  ls  ========\n");
// printf("%s", ls(cmd));
// printf("===== ft ls =======\n");
// printf("%s", ft_ls(cmd));
// printf("==================\n");

// UT_ASSERT(strcmp(ls("-1R ~/Downloads > ./ls_out"), ft_ls("-1R ~/Downloads > ./ft_ls_out")) == 0);

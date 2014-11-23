char *cmd;

cmd = "";
reset_sandbox();
sandbox_cmd("mkdir dir{1..5} .hdir{1..5}");
sandbox_cmd("touch dir1/file{1..5} dir1/.hfile{1..5}");
sandbox_cmd("touch .hdir1/file{1..5} .hdir1/.hfile{1..5}");
sandbox_cmd("touch .hdir1/file{1..5} .hdir1/.hfile{1..5}");
sandbox_cmd("touch a && ln -s a symlink");

cmd = "-lR .";

// printf("\n===================\n");
// printf("%s", ls(cmd));
// printf("\n===================\n");
// printf("%s", ft_ls(cmd));
// printf("\n===================\n");

UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);

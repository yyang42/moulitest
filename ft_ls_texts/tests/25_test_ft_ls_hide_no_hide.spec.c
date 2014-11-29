char *cmd;

cmd = "-lR";

reset_sandbox();

sandbox_cmd("mkdir .dirA && mkdir .dirA/dirB && touch .dirA/dirB/file");
UT_ASSERT_W(strcmp(ls(cmd), ft_ls(cmd)) == 0);

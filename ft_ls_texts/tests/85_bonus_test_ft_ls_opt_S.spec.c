char *cmd = "-1S";
char *rcmd = "-1Sr";

reset_sandbox();
sandbox_cmd("touch a b c d e && head -c 42 /dev/random > c");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
UT_ASSERT(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);

reset_sandbox();
sandbox_cmd("touch a && head -c 42 /dev/random > a && touch b && head -c 21 /dev/random > b && \
			 touch c && head -c 56 /dev/random > c");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
UT_ASSERT(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);

reset_sandbox();
sandbox_cmd("touch fileA{1..5} fileB{1..5} fileC{1..5} && \
			 head -c 42 /dev/random > fileA1 && \
			 head -c 42 /dev/random > fileA2 && \
			 head -c 42 /dev/random > fileA3 && \
			 head -c 42 /dev/random > fileA4 && \
			 head -c 42 /dev/random > fileA5");
UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
UT_ASSERT(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);

reset_sandbox();
sandbox_cmd("touch a && head -c 42 /dev/random > a");
sandbox_cmd("touch b && head -c 56 /dev/random > b");
sandbox_cmd("touch c && head -c 32 /dev/random > c");
sandbox_cmd("touch d && head -c 32 /dev/random > d");
sandbox_cmd("touch e && head -c 98 /dev/random > e");
sandbox_cmd("touch f && head -c 54 /dev/random > f");
sandbox_cmd("touch g");
sandbox_cmd("touch h && head -c 8 /dev/random > h");

UT_ASSERT(strcmp(ls(cmd), ft_ls(cmd)) == 0);
UT_ASSERT(strcmp(ls(rcmd), ft_ls(rcmd)) == 0);

/*
printf("\n=====  ls  ========\n");
printf("%s", ls(cmd));
printf("===== ft ls =======\n");
printf("%s", ft_ls(cmd));
printf("==================\n");
*/

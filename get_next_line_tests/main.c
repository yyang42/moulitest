#include <testframework.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc/malloc.h>
#include <ctype.h>
#include <math.h>
#include <get_next_line.h>
#include <stdio.h>
#include <fcntl.h>
#include <regex.h>

<DEF_BLOCK>

#define FT_LS_PATH RENDU_PATH"/ft_ls"

<TEST_DEF_BLOCK>

int	main(void)
{
<MAIN_TEST_BLOCK>

	UT_RUN_ALL_TESTS();
	return (0);
}

#include <testframework.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc/malloc.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <regex.h>

PROTOS

int	main(void)
{
	ADD_TESTS
	printf("%s\n", RENDU_PATH);
	UT_RUN_ALL_TESTS();
	return (0);
}

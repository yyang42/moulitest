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
#include <project.h>

PROTOTYPES

int	main(void)
{
	ADD_TESTS
	UT_RUN_ALL_TESTS();
	return (0);
}

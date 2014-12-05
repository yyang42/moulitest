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
	ut_run_all_tests();
	return (0);
}

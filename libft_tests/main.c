#include <testframework.h>

PROTOTYPES

int	main(void)
{
	printf("\n");
	printf("WARNING: NULL cases are not tested on purpose. Contributors of the following tests consider that testing NULL is a bad practice.\n");
	printf("\n");
	ADD_TESTS
	ut_run_all_tests();
	return (0);
}

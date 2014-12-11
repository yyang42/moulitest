#include <project.h>

PROTOTYPES

int	main(void)
{
	ADD_TESTS
	printf("\033[33mBuffer size should be set to 8 for these tests\033[m\n");
	ut_run_all_tests();
	return (0);
}

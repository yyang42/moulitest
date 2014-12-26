#include <testframework.h>
#include <locale.h>

PROTOTYPES

int	main(void)
{
	ADD_TESTS
	if (setlocale(LC_ALL, "") == NULL)
		printf("\033[31m/!\\ Failed to set locale. Test 40 will break. /!\\\033[m\n");
	ut_run_all_tests();
	return (0);
}

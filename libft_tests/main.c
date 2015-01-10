// #include <project.h>

// PROTOTYPES

// int	main(void)
// {
// 	printf("\n");
// 	printf("WARNING: NULL cases are not tested on purpose. Contributors of the following tests consider that testing NULL is a bad practice.\n");
// 	printf("\n");
// 	ADD_TESTS
// 	ut_run_all_tests();
// 	return (0);
// }
#include <unistd.h>
#include <string.h>
#include <fw.h>
#include <mt.h>
#include <test.h>
#include <signal.h>
#include <locale.h>
#include "project.h"

# define MT_ADD_PROTO(name)			void suite_ ## name(t_suite *suite)


PROTOTYPES


int main()
{
	t_mt	*mt = mt_create("libft");

	ADD_TESTS

	mt_exec(mt);
	return(0);
}

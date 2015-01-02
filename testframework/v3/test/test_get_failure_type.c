#include <test.h>
#include <stdio.h>
#include <color.h>

char	*test_get_failure_type(t_test *test)
{

	if (test->sig == SIGABRT)
		return (strdup("FAIL"));
	else if (test->sig == SIGSEGV)
		return (strdup("SEGV"));
	else if (test->sig == SIGBUS)
		return (strdup("BUS!"));
	else if (test->sig == SIGALRM)
		return (strdup("TIME"));
	else
		return (strdup("OK !"));
}

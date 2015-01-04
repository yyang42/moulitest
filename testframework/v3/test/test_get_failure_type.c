#include <test.h>
#include <stdio.h>
#include <color.h>
#include <signal.h>

char	*test_get_failure_type(t_test *test)
{
	if (test->is_fail)
	{
		if (test->sig == SIGABRT)
			return (strdup("ABRT"));
		else if (test->sig == SIGSEGV)
			return (strdup("SEGV"));
		else if (test->sig == SIGBUS)
			return (strdup("BUS!"));
		else if (test->sig == SIGALRM)
			return (strdup("TIME"));
		else
			return (strdup("FAIL"));
	}
	else
	{
		return (strdup("OK !"));
	}
}

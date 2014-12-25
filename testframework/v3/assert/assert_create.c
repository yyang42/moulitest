#include <mt_assert.h>
#include <string.h>
#include <stdlib.h>

t_assert			*assert_create(char *name)
{
	t_assert	*an_assert;

	an_assert = (t_assert *)malloc(sizeof(t_assert));
	an_assert->name = strdup(name);
	return (an_assert);
}

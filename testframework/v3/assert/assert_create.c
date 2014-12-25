#include <assert.h>
#include <string.h>
#include <stdlib.h>

t_assert			*assert_create(char *name)
{
	t_assert	*assert;

	assert = (t_assert *)malloc(sizeof(t_assert));
	assert->name = strdup(name);
	return (assert);
}

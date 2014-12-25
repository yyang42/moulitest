#include <mt_assert.h>
#include <stdlib.h>

void	assert_exec(t_assert *an_assert, int cond_res)
{
	if (cond_res == 0)
		abort();
	(void)an_assert;
	(void)cond_res;
}

#include <string.h>
#include <fw.h>
#include <mt.h>
#include <test.h>
#include <project.h>

PROTOTYPES

int main()
{
	t_mt	*mt = mt_create("ft_sh1 (beta, not complete)");

	ADD_TESTS

	mt_exec(mt);
	return(0);
}

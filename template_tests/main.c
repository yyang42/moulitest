#include <string.h>
#include <fw.h>
#include <mt.h>
#include <test.h>
#include <project.h>

PROTOTYPES

int main()
{
	t_mt	*mt = mt_create("sample test");

	ADD_TESTS

	mt_exec(mt);
	return(0);
}

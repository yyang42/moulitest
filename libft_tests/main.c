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

	setbuf(stdout, NULL);

	ADD_TESTS

	mt_exec(mt);
	return(0);
}

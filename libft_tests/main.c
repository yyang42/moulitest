#include <unistd.h>
#include <string.h>
#include <fw.h>
#include <mt.h>
#include <test.h>
#include <signal.h>
#include <locale.h>
#include "project.h"

PROTOTYPES


int main()
{
	t_mt	*mt = mt_create("libft");

	mt->desc = "Errors should never pass silently! (That's why we don't handle NULL cases.)";
	setbuf(stdout, NULL);

	ADD_TESTS

	mt_exec(mt);
	return(0);
}

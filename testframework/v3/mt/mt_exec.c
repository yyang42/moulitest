#include <mt.h>
#include <color.h>

static void		mt_exec_suites(t_mt *mt)
{
	lst_iter(mt->suites, (void *)suite_exec);
}

static void		mt_print_header(t_mt *mt)
{
	puts("[ "C_CYAN"-------STARTING ALL UNIT TESTS-------"C_CLEAR" ]");
	(void)mt;
}

static void		mt_print_footer(t_mt *mt)
{

	// printf(C_WHITE"End of test : %d out of %d test passed."C_CLEAR"\n", count - _test_fails, count);
	puts("[ "C_CYAN"----------END OF UNIT TESTS----------"C_CLEAR" ]");
	puts("[ Source: github.com/yyang42/moulitest  ]");
	(void)mt;
}

void			mt_exec(t_mt *mt)
{
	mt_print_header(mt);
	mt_exec_suites(mt);
	mt_print_footer(mt);
}

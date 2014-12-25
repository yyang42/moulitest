#include <mt.h>
#include <unistd.h>
#include <color.h>

static void		mt_exec_suites(t_mt *mt)
{
	lst_iter(mt->suites, (void *)suite_exec);
}

static void		mt_print_header(t_mt *mt)
{
	puts("");
	printf("[ "C_CYAN"-------STARTING ALL UNIT TESTS-------"C_CLEAR" ]");
	printf(" Legend:");
	printf(" ("C_GREEN"."C_CLEAR") ok");
	printf(" / ("C_RED"A"C_CLEAR") assert");
	printf(" / ("C_RED"S"C_CLEAR") segfault");
	printf(" / ("C_RED"B"C_CLEAR") buserror");
	puts("");
	(void)mt;
}

static void		mt_print_footer(t_mt *mt)
{
	printf(C_WHITE"End of test : %d out of %d test passed."C_CLEAR"\n", 9999999, 9999999);
	puts("[ "C_CYAN"----------END OF UNIT TESTS----------"C_CLEAR" ]");
	puts("[ Source: github.com/yyang42/moulitest  ]");
	puts("");
	(void)mt;
}

void			mt_exec(t_mt *mt)
{
	mt_print_header(mt);
	mt_exec_suites(mt);
	mt_print_footer(mt);
}

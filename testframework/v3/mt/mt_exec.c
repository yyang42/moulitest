#include <mt.h>
#include <unistd.h>
#include <color.h>

static void		mt_exec_suites(t_mt *mt)
{
	lst_iter(mt->suites, (void *)suite_exec);
}

static void		mt_print_header(t_mt *mt)
{
	printf("\n--\n\n");
	printf(C_CYAN">>>> Tests for %s"C_CLEAR"\n", mt->name);
	// printf("=== Tests for %s ===\n", mt->name);
	// printf("Test: %s\n", mt->name);
	printf("Source: github.com/yyang42/moulitest\n");
	printf("Legend:");
	printf(" ("C_GREEN"."C_CLEAR") Ok");
	printf(" / ("C_RED"F"C_CLEAR") Fail");
	printf(" / ("C_RED"S"C_CLEAR") Segfault");
	printf(" / ("C_RED"B"C_CLEAR") Bus error");
	printf(" / ("C_RED"T"C_CLEAR") Timeout");
	printf(" / ("C_RED"A"C_CLEAR") Abort");
	puts("\n");
	if (mt->desc)
		printf("Notes: %s\n\n", mt->desc);
	printf("[ "C_CYAN"-------STARTING ALL UNIT TESTS-------"C_CLEAR" ]");
	puts("");
	(void)mt;
}

static void		mt_print_result(t_mt *mt)
{
	char *color;

	if (mt_count_failed_suites(mt) > 0)
		color = C_RED;
	else
		color = C_GREEN;
	printf(color);
	printf(">>>> Result: %lu/%lu test suites passed.",
		lst_len(mt->suites) - mt_count_failed_suites(mt)
		, lst_len(mt->suites));

	size_t total_tests = mt_count_tests(mt);
	printf(" %lu/%lu tests passed (dots).", total_tests - mt_count_failed_tests(mt), total_tests);
	printf(C_CLEAR);
	puts("");
}

static void		mt_print_footer(t_mt *mt)
{
	puts("[ "C_CYAN"----------END OF UNIT TESTS----------"C_CLEAR" ]");
	puts("");
	mt_print_result(mt);
	puts("");
}

void			mt_exec(t_mt *mt)
{
	mt_print_header(mt);
	mt_exec_suites(mt);
	mt_print_footer(mt);
}

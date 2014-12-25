#include <mt.h>
#include <test.h>
#include <stdio.h>
#include <lst.h>
#include <color.h>

static void		suite_print_prefix(t_suite *suite)
{
	char	*ut;
	int		ut_len;

	ut = "["C_YELLOW"UT"C_CLEAR"] ";
	ut_len = 5;

	printf("\r");
	printf("%s", ut);
	printf("%s", suite->name);
	printf(" %.*s", (MAIN_COL_WIDTH - ut_len - (int)strlen(suite->name) - 8),
		"________________________________________________");
}

static void		suite_print_first_failure(t_suite *suite)
{
	t_test		*test;
	t_lst_elem	*elem;

	elem = lst_find(suite->tests, (void *)test_filter_failed);
	if (elem)
	{
		test = elem->data;
		fprintf(stdout, C_RED" %s: %s"C_CLEAR,
			test->name,
			test->last_assert_cond);
	}
}

static void		suite_print_suite_summary(t_suite *suite)
{
	if (!lst_len(suite->tests))
		fprintf(stdout, "[\?\?\?\?]");
	else if (suite_count_fails(suite))
		fprintf(stdout, C_RED"[FAIL]"C_CLEAR);
	else
		fprintf(stdout, C_GREEN"[Ok !]"C_CLEAR);
}

static void		suite_print_result(t_suite *suite)
{
	suite_print_prefix(suite);
	fprintf(stdout, " ");
	suite_print_suite_summary(suite);
	fprintf(stdout, " ");
	lst_iter(suite->tests, (void *)test_print);
	suite_print_first_failure(suite);
}

void			suite_exec(t_suite *suite)
{
	suite_print_result(suite);
	suite->fn(suite);
	lst_iter(suite->tests, (void *)test_exec);
	suite_print_result(suite);
	puts("");
}

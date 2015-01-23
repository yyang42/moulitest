#include <mt.h>
#include <test.h>
#include <stdio.h>
#include <mt_lst.h>
#include <color.h>

static void		suite_print_prefix(t_suite *suite)
{
	int		ut_len;
	char	*file_suffix = ".spec.c";
	char	suite_name[10 * 1000];

	ut_len = 5;

	printf("\r");
	printf("%s", ""C_YELLOW">>>> "C_CLEAR);
	sprintf(suite_name, "%s%s %.*s",
		suite->name,
		file_suffix,
		(MAIN_COL_WIDTH
			- ut_len
			- (int)strlen(suite->name)
			- (int)strlen(file_suffix)
			- 8),
			"---------------------------------------------------------------------");
	printf("%.*s", MAIN_COL_WIDTH - 12, suite_name);
}

static void		suite_print_first_failure(t_suite *suite)
{
	t_test		*test;
	t_mt_lst_elem	*elem;
	size_t		max_msg_length = 80;
	char		*suffix;

	elem = mt_lst_find(suite->tests, (void *)test_filter_failed);
	if (!elem)
		return ;
	test = elem->data;
	printf(C_RED);
	printf(" [%s]", test_get_failure_type(test));
	fprintf(stdout, " %s", test->name);
	if (test->msg)
		suffix = test->msg;
	else
		suffix = test->last_assert_cond;

	printf(" -> %.*s", (int)max_msg_length, suffix);
	if (suffix && (strlen(suffix) > max_msg_length))
		printf("...");
	printf(C_CLEAR);
}

static void		suite_print_suite_summary(t_suite *suite)
{
	if (!mt_lst_len(suite->tests))
		fprintf(stdout, "[\?\?\?\?]");
	else if (suite_count_failed_tests(suite))
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
	mt_lst_iter(suite->tests, (void *)test_print);
	suite_print_first_failure(suite);
}

void			suite_exec(t_mt_lst_elem *elem)
{
	t_suite *suite;

	suite = elem->data;
	suite_print_result(suite);
	suite->fn(suite);
	mt_lst_iter(suite->tests, (void *)test_exec);
	suite_print_result(suite);
	puts("");
}

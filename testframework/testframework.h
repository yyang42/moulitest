#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include <stdio.h>
# include <signal.h>

# define C_CLEAR "\033[0m"
# define C_YELLOW "\033[33m"
# define C_RED "\033[31;1m"
# define C_GREEN "\033[32;1m"
# define C_CYAN "\033[36;1m"
# define C_WHITE "\033[37;1m"
# define C_BLUE "\033[34;1m"

# define UT_TEST(name)			void ut_test_ ## name(int *param)
# define UT_ASSERT_W(cond)		is_warning = 1; UT_ASSERT_EXEC(cond)
# define UT_ASSERT(cond)		is_warning = 0; UT_ASSERT_EXEC(cond)
# define UT_ASSERT_EXEC(cond)	ut_last_cond = #cond; \
								if(!(cond)) { \
									if (!ut_last_err) \
									{ \
										ut_last_err = #cond; \
										if (!is_warning) \
											*param = 1; \
									} \
									if (is_warning) \
										strcat(ut_test_symbol, C_YELLOW"X"C_CLEAR); \
									else \
										strcat(ut_test_symbol, C_RED"X"C_CLEAR); \
								} else { \
									strcat(ut_test_symbol, C_GREEN"."C_CLEAR); \
								} \
								is_warning = 0;
# define UT_SEGV(test_)			printf("["C_RED"FAIL"C_CLEAR"] %s"C_BLUE"SEGV"C_CLEAR, ut_test_symbol); \
								if (ut_last_cond) \
									printf(" ERROR: %s", ut_last_cond); \
								printf("\n"); \
								*ut_test_symbol = '\0'; \
								ut_last_cond = '\0';

# define UT_ADD_TEST(name)		ut_add_test_(&ut_test_ ## name, #name)
# define UT_RUN_ALL_TESTS()		ut_run_all_tests_()

/*
 *  Bonus
 */

# define UT_ASSERT_EQ(a, b)		UT_ASSERT((a) == (b))
# define UT_ASSERT_EQ_STR(a, b)	UT_ASSERT(a && b && strcmp(a, b))
# define UT_ASSERT_NEQ(a, b)	UT_ASSERT((a) != (b))

typedef	void (*ut_test)(int *);

typedef struct				ut_test_list_s
{
	ut_test					test;
	char					*name;
	int						is_fail;
	struct ut_test_list_s	*next;

}							ut_test_list_t;

extern ut_test_list_t		*ut_tests;
extern int					is_warning;
extern char					*ut_last_err;
extern char					*ut_last_cond;
extern char					ut_test_symbol[100000];

void						ut_sigsegv_(int);
ut_test_list_t				*ut_create_list_(ut_test, char *);
void						ut_add_test_(ut_test, char *);
int							ut_run_all_tests_(void);
int							strequ(const char *s1, const char *s2);
#endif /* !UNIT_TEST_H */

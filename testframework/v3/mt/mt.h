typedef struct				s_test
{
	char					*name;
	int						is_success;
	int						test_type;
}							t_test;

typedef struct				s_suite
{
	char					*name;
	t_test					**tests;
	int						x_success_count;
	int						x_warning_count;
}							t_suite;

typedef struct				s_mt
{
	char					*name;
	t_suite					**suites;
}							t_mt;

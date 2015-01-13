#include <project.h>

static void simple_string(t_test *test)
{
    char 	*line = NULL;
    
	mt_assert(get_next_line(-99, NULL) == -1);
	mt_assert(get_next_line(-1, NULL) == -1);
	mt_assert(get_next_line(1, NULL) == -1);
	mt_assert(get_next_line(99, NULL) == -1);

	mt_assert(get_next_line(-99, &line) == -1);
	mt_assert(get_next_line(-1, &line) == -1);

	/* Not opened fd */
	mt_assert(get_next_line(42, &line) == -1);
}

void	suite_05_test_error_handling(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}

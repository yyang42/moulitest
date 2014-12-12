#include <project.h>

UT_TEST(05_test_error_handling)
{
	UT_ASSERT_EQ(get_next_line(-99, NULL), -1);
	UT_ASSERT_EQ(get_next_line(-1, NULL), -1);
	UT_ASSERT_EQ(get_next_line(1, NULL), -1);
	UT_ASSERT_EQ(get_next_line(99, NULL), -1);

	char 	*line = NULL;
	UT_ASSERT_EQ(get_next_line(-99, &line), -1);
	UT_ASSERT_EQ(get_next_line(-1, &line), -1);
	// UT_ASSERT_NEQ(get_next_line(0, &line), -1);

	/* Not opened fd */
	UT_ASSERT_EQ(get_next_line(42, &line), -1);
}

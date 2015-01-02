#include <project.h>
#include <limits.h>

static void test_octal_neg(t_test *test)
{
	// debug_next_assert();
	assert_printf("%o, %ho, %hho", -42, -42, -42);
}

void	suite_90_incomptbl_values_sdp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_octal_neg);\
}

#include <project.h>

static void todo(t_test *test)
{
	// negative octal
	assert_printf("%o", -42);
}

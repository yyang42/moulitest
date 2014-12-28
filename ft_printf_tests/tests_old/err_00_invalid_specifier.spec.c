#include "project.h"

UT_TEST(err_00_invalid_specifier)
{
	// Do not remove the 42, build will fail otherwise
	UT_PRINTF_ASSERT("An invalid specifier %r, and you fail (or not)\n", 42);
}

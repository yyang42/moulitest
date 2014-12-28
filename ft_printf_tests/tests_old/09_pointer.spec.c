#include "project.h"

UT_TEST(09_pointer)
{
	char *str = "Chaine de test";
	int i;
	unsigned long l;
	UT_PRINTF_ASSERT("%p\n", str);
	UT_PRINTF_ASSERT("%p\n", &i);
	UT_PRINTF_ASSERT("%p\n", &l);
	UT_PRINTF_ASSERT("%p\n", &strlen);
}

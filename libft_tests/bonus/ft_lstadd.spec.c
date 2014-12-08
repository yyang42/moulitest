#include "project.h"

UT_TEST(ft_lstadd)
{
	t_list	*list;
	t_list	*list2;

	list = malloc(sizeof(t_list));
	list2 = malloc(sizeof(t_list));
	bzero(list, sizeof(t_list));
	bzero(list2, sizeof(t_list));
	ft_lstadd(&list2, list);
	UT_ASSERT_EQ(list, list2);
	UT_ASSERT_NEQ(list->next, NULL);

	/* test edge cases */
	ft_lstadd(NULL, NULL);
}

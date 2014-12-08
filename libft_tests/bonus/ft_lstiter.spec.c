#include "project.h"

UT_TEST(ft_lstiter)
{
	t_list	*list;

	bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
	bzero(((list->next) = malloc(sizeof(t_list))), sizeof(t_list));
	ft_lstiter(list, lstiter_test);
	UT_ASSERT_EQ(list->content_size, 42);
	UT_ASSERT_EQ(list->next->content_size, 42);
}

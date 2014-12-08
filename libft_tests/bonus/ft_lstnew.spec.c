#include "project.h"

UT_TEST(ft_lstnew)
{
	t_list	*list;
	int		ft;

	ft = 42;
	list = ft_lstnew(&ft, sizeof(int));
	UT_ASSERT_EQ((*(int*)(list->content)), 42);
	list = ft_lstnew(NULL, 386);
	UT_ASSERT_EQ((list->content_size), 0);
}

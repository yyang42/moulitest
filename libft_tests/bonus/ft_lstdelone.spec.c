#include "project.h"

extern int ____diddel;

UT_TEST(ft_lstdelone)
{
	t_list	*list;
	int		ft;

	____diddel = 0;
	ft = 42;
	list = (t_list *)malloc(sizeof(t_list));
	list->content = &ft;
	list->content_size = sizeof(int);
	ft_lstdelone(&list, del_test);
	UT_ASSERT_EQ(list, NULL);
	UT_ASSERT_EQ(____diddel, 1);

	/* test edge cases */
	ft_lstdelone(NULL, NULL);
}

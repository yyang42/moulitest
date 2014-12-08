#include "project.h"

extern int ____diddel;

UT_TEST(ft_lstdel)
{
	t_list	*list;
	int		ft;

	ft = 42;
	____diddel = 0;
	list = malloc(sizeof(t_list));
	bzero(list, sizeof(t_list));
	list->next = malloc(sizeof(t_list));
	bzero(list->next, sizeof(t_list));
	list->content = &ft;
	list->next->content = (&ft) + 1;
	ft_lstdel(&list, del_test);
	UT_ASSERT_EQ(list, NULL);
	UT_ASSERT_EQ(____diddel, 2);

	/* test edge cases */
	ft_lstdel(NULL, NULL);
}

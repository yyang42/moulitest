#include <project.h>

static int ____diddel;

static void	del_test(void *data, size_t i)
{
	(void)data;
	(void)i;
	____diddel++;
}

static void test1(t_test *test)
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
	mt_assert(list == NULL);
	mt_assert(____diddel == 2);
}

void	suite_02_bonus_ft_lstdel(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
}

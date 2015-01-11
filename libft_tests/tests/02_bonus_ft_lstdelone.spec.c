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

	____diddel = 0;
	ft = 42;
	list = (t_list *)malloc(sizeof(t_list));
	list->content = &ft;
	list->content_size = sizeof(int);
	ft_lstdelone(&list, del_test);
	mt_assert(list == NULL);
	mt_assert(____diddel == 1);
}

void	suite_02_bonus_ft_lstdelone(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
}

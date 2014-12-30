#include "lst.h"

size_t		lst_count(t_lst *lst, void *(*f)(void *))
{
	int			len;
	t_lst_elem	*elem;

	len = 0;
	elem = lst->elems;
	while (elem)
	{
		if (f(elem->data))
			len++;
		elem = elem->next;
	}
	return (len);
}

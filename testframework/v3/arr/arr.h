#ifndef ARR_H
# define ARR_H
# include <stddef.h>

size_t	arr_size(void *arr);
void	*arr_rev(void *arr);
void	*arr_cpy(void *arr);
void	arr_del(void *arr_ptr);

#endif
